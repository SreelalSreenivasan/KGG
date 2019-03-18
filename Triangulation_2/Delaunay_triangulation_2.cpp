#include <fstream>
#include <thread>
#include <chrono>
#include <cmath>

// CGAL headers
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Qt/Converter.h>
#include <CGAL/point_generators_2.h>
#include <CGAL/squared_distance_2.h>
#include <CGAL/Circle_2.h>
#include <CGAL/enum.h>
#include <CGAL/number_utils.h>
#include <CGAL/Cartesian.h>
#include <CGAL/Exact_rational.h>
#include <CGAL/Arr_circle_segment_traits_2.h>
#include <CGAL/Arrangement_2.h>



// Qt headers
#include <QtGui>
#include <QString>
#include <QActionGroup>
#include <QFileDialog>
#include <QInputDialog>
#include <QLineF>
#include <QPointF>
#include <QPen>
#include <QGraphicsEllipseItem>
#include <QPropertyAnimation>
#include <QThread>

// GraphicsView items and event filters (input classes)
#include "TriangulationCircumcircle.h"
#include "TriangulationMovingPoint.h"
#include "TriangulationConflictZone.h"
#include "TriangulationRemoveVertex.h"
#include "TriangulationPointInputAndConflictZone.h"
#include <CGAL/Qt/TriangulationGraphicsItem.h>
#include <CGAL/Qt/VoronoiGraphicsItem.h>

// for viewportsBbox
#include <CGAL/Qt/utility.h>

// the two base classes
#include "ui_Delaunay_triangulation_2.h"
#include <CGAL/Qt/DemosMainWindow.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef K::Iso_rectangle_2 Iso_rectangle_2;

typedef CGAL::Delaunay_triangulation_2<K> Delaunay;

typedef Delaunay::Point Point;

typedef std::pair<double,double> pairs;

// typedef CGAL::Cartesian<CGAL::Exact_rational>   kernal;
//typedef kernal::Circle_2    circle;
//typedef K::Circle_2         circle;
//typedef CGAL::Arr_circle_segment_traits_2<K>   traits;
//typedef traits::Curve_2     curve;



//typedef CGAL::Arrangement_2<traits>     Arrangement;




class MainWindow :
  public CGAL::Qt::DemosMainWindow,
  public Ui::Delaunay_triangulation_2
{
  Q_OBJECT

private:
  Delaunay dt;
  QGraphicsScene scene;
  QGraphicsLineItem *qline[500];
  QGraphicsLineItem *qline1[500];
  QGraphicsEllipseItem *ellipse[500];
  QGraphicsEllipseItem *move[500];
  QTimeLine *timer[500] ;
  QGraphicsItemAnimation *anim[500];



  Point_2 x,y;
  int j=0;
  int m_size=0;

  std::vector<K::Point_2> d_points;
  std::vector<Point_2> g_points1;
  std::vector<Point_2> g_points2;
  std::set<std::pair<double,double>> m_points;
  //std::vector<std::pair<double,double>> m_points_2;

  std::vector<std::pair<Point_2,Point_2>> edge_vect;
  std::vector<std::pair<Point_2,Point_2>> edge_vect2;
  std::vector<std::pair<double,double>> vel_vect;

  CGAL::Qt::TriangulationGraphicsItem<Delaunay> * dgi;
  CGAL::Qt::VoronoiGraphicsItem<Delaunay> * vgi;
  CGAL::Qt::TriangulationGraphicsItem<Delaunay> * gg;



  /*QPushButton *button = new QPushButton("Button1");
  button->show();
  QPropertyAnimation anim(button,"geometry");
  anim.setDuration(3000);
  anim.setStartValue(QRect(-88,-40,100,30));
  anim.setEndValue(QRect(-100,-50,100,30));

  QPushButton button2("Button2");
  button2.show();

  QPropertyAnimation anim2(&button2,"geometry");
  anim2.setDuration(5000);
  anim2.setStartValue(QRect(-200,-70,100,30));
  anim2.setEndValue(QRect(-300,-150,100,30));

  QParallelAnimationGroup *animgroup=new QParallelAnimationGroup;
  animgroup->addAnimation(&anim);
  animgroup->addAnimation(&anim2);

  QPushButton button3("Button3");
  button3.show();

  QPropertyAnimation anim3(&button2,"geometry");
  anim3.setDuration(2000);
  anim3.setStartValue(QRect(-250,-100,100,30));
  anim3.setEndValue(QRect(-320,-50,100,30));

  QSequentialAnimationGroup animseq;
  animseq.addAnimation(&anim3);
  animseq.addAnimation(animgroup);
  animseq.start();*/



  CGAL::Qt::TriangulationMovingPoint<Delaunay> * mp;
  CGAL::Qt::TriangulationConflictZone<Delaunay> * cz;
  CGAL::Qt::TriangulationRemoveVertex<Delaunay> * trv;
  CGAL::Qt::TriangulationPointInputAndConflictZone<Delaunay> * pi;
  CGAL::Qt::TriangulationCircumcircle<Delaunay> *tcc;

public:
  MainWindow();

public Q_SLOTS:

  void processInput(CGAL::Object o);

  void compute_gabriel();

  void clear_DS();

  void draw_circle(Point_2,Point_2);

  void on_actionMovingPoint_toggled(bool checked);

  void on_actionShowConflictZone_toggled(bool checked);

  void on_actionCircumcenter_toggled(bool checked);

  void on_actionShowDelaunay_toggled(bool checked);

  void on_actionShowVoronoi_toggled(bool checked);

  void on_actionShowGabriel_toggled(bool checked);

  void on_actionInsertPoint_toggled(bool checked);

  void on_actionPlay_toggled(bool checked);

  void on_actionInsertRandomPoints_triggered();

  void on_actionVelocity_triggered();

  void on_actionLoadPoints_triggered();

  void on_actionSavePoints_triggered();

  void on_actionClear_triggered();

  void on_actionRecenter_triggered();

  virtual void open(QString fileName);

  virtual void open_velocity(QString fileName);

Q_SIGNALS:
  void changed();
};


MainWindow::MainWindow()
  : DemosMainWindow()
{
  setupUi(this);


  for(int i=0;i<500;i++)
  {
      qline[i]=new QGraphicsLineItem();
      qline[i]->setPen(QPen(Qt::green,0,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
      qline[i]->hide();
  }
  for(int i=0;i<500;i++)
  {
      qline1[i]=new QGraphicsLineItem();
      qline1[i]->setPen(QPen(Qt::black,0,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
      qline1[i]->hide();
  }


  this->graphicsView->setAcceptDrops(false);

  // Settings for drawing ellipse


  // Add a GraphicItem for the Delaunay triangulation
  dgi = new CGAL::Qt::TriangulationGraphicsItem<Delaunay>(&dt);

  QObject::connect(this, SIGNAL(changed()),
           dgi, SLOT(modelChanged()));

  dgi->setVerticesPen(QPen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
  scene.addItem(dgi);

  // Add a GraphicItem for the Voronoi diagram
  vgi = new CGAL::Qt::VoronoiGraphicsItem<Delaunay>(&dt);

  QObject::connect(this, SIGNAL(changed()),
           vgi, SLOT(modelChanged()));

  vgi->setEdgesPen(QPen(Qt::blue, 0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
  scene.addItem(vgi);
  vgi->hide();

  //Add a graphicitem foor Gabriel edges
  gg=new CGAL::Qt::TriangulationGraphicsItem<Delaunay>(&dt);

  QObject::connect(this,SIGNAL(changed()),
                   gg, SLOT(modelChanged()));
  //gg->setEdgesPen(QPen(Qt::green,0,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
  //scene.addItem(gg);
  //gg->hide();

  // Setup input handlers. They get events before the scene gets them
  // and the input they generate is passed to the triangulation with
  // the signal/slot mechanism
  pi = new CGAL::Qt::TriangulationPointInputAndConflictZone<Delaunay>(&scene, &dt, this );

  QObject::connect(pi, SIGNAL(generate(CGAL::Object)),
           this, SLOT(processInput(CGAL::Object)));

  mp = new CGAL::Qt::TriangulationMovingPoint<Delaunay>(&dt, this);
  // TriangulationMovingPoint<Delaunay> emits a modelChanged() signal each
  // time the moving point moves.
  // The following connection is for the purpose of emitting changed().
  QObject::connect(mp, SIGNAL(modelChanged()),
           this, SIGNAL(changed()));

  trv = new CGAL::Qt::TriangulationRemoveVertex<Delaunay>(&dt, this);
  QObject::connect(trv, SIGNAL(modelChanged()),
           this, SIGNAL(changed()));

  tcc = new CGAL::Qt::TriangulationCircumcircle<Delaunay>(&scene, &dt, this);
  tcc->setPen(QPen(Qt::red, 0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

  cz = new CGAL::Qt::TriangulationConflictZone<Delaunay>(&scene, &dt, this);

  //
  // Manual handling of actions
  //

  QObject::connect(this->actionQuit, SIGNAL(triggered()),
           this, SLOT(close()));

  // We put mutually exclusive actions in an QActionGroup
  QActionGroup* ag = new QActionGroup(this);
  ag->addAction(this->actionInsertPoint);
  ag->addAction(this->actionMovingPoint);
  ag->addAction(this->actionCircumcenter);
  ag->addAction(this->actionShowConflictZone);
  //ag->addAction(this->)
  // Check two actions
  this->actionInsertPoint->setChecked(true);
  this->actionShowDelaunay->setChecked(true);

  //
  // Setup the scene and the view
  //
  scene.setItemIndexMethod(QGraphicsScene::NoIndex);
  scene.setSceneRect(-100, -100, 100, 100);
  this->graphicsView->setScene(&scene);
  this->graphicsView->setMouseTracking(true);

  // Turn the vertical axis upside down
  this->graphicsView->matrix().scale(1, -1);

  // The navigation adds zooming and translation functionality to the
  // QGraphicsView
  this->addNavigation(this->graphicsView);

  this->setupStatusBar();
  this->setupOptionsMenu();
  this->addAboutDemo(":/cgal/help/about_Delaunay_triangulation_2.html");
  this->addAboutCGAL();
  this->setupExportSVG(actionExport_SVG, graphicsView);

  this->addRecentFiles(this->menuFile, this->actionQuit);
  connect(this, SIGNAL(openRecentFile(QString)),
      this, SLOT(open(QString)));
}


void
MainWindow::processInput(CGAL::Object o)
{
  Point_2 p;
  if(CGAL::assign(p, o)){
    dt.insert(p);
  }
  Q_EMIT( changed());
}


/*
 *  Qt Automatic Connections
 *  http://doc.qt.io/qt-5/designer-using-a-ui-file.html#automatic-connections
 *
 *  setupUi(this) generates connections to the slots named
 *  "on_<action_name>_<signal_name>"
 */
void
MainWindow::on_actionInsertPoint_toggled(bool checked)
{
  if(checked){
    scene.installEventFilter(pi);
    scene.installEventFilter(trv);
  } else {
    scene.removeEventFilter(pi);
    scene.removeEventFilter(trv);
  }
}


void
MainWindow::on_actionMovingPoint_toggled(bool checked)
{

  if(checked){
    scene.installEventFilter(mp);
  } else {
    scene.removeEventFilter(mp);
  }
}


void
MainWindow::on_actionShowConflictZone_toggled(bool checked)
{

  if(checked){
    scene.installEventFilter(cz);
  } else {
    scene.removeEventFilter(cz);
  }
}

void
MainWindow::on_actionCircumcenter_toggled(bool checked)
{
  if(checked){
    scene.installEventFilter(tcc);
    tcc->show();
  } else {
    scene.removeEventFilter(tcc);
    tcc->hide();
  }
}


void
MainWindow::on_actionShowDelaunay_toggled(bool checked)
{
  dgi->setVisibleEdges(checked);
}


//Darw circle: QPainter way
void
MainWindow::draw_circle(Point_2 c1,Point_2 c2)
{
    QPainter qp(this);
    double r=std::sqrt(std::pow(c1.x()-c2.x(),2)+std::pow(c1.y()-c2.y(),2));
    double x=0;
    double y=r;
    double p;
    double xc=c1.x();
    double yc=c1.y();


    qp.drawPoint(xc+x,yc-y);
    qp.setPen(QPen(Qt::red,5,Qt::DashDotLine));
    p=1-r;
    for(x=0;x<=y;x++)
        {
            if(p<0)
            {
                y=y;
                p=(p+(2*x)+3);
            }
            else
            {
                y=y-1;
                p=p+((2*(x-y))+5);
            }
            qp.drawPoint(xc+x,yc-y);
            qp.drawPoint(xc-x,yc-y);
            qp.drawPoint(xc+x,yc+y);
            qp.drawPoint(xc-x,yc+y);
            qp.drawPoint(xc+y,yc-x);
            qp.drawPoint(xc-y,yc-x);
            qp.drawPoint(xc+y,yc+x);
            qp.drawPoint(xc-y,yc+x);
        }

}
void
MainWindow::on_actionShowGabriel_toggled(bool checked)
{
    Point_2 c;
    QTransform transform;
    if(checked)
    {
        //transform.translate(50,50);
        /*QPen pen;
        pen.setColor(QColor(Qt::red));
        pen.setWidth(5);
        Point_2 c1=Point_2(250,300);
        Point_2 c2=Point_2(400,500);
        CGAL::Exact_rational sq=CGAL::Exact_rational(100);
        circle cir=circle(c1,c2,CGAL::CLOCKWISE);
        curve cv=curve(cir);

        //Arrangement arr;

        //insert(arr,cv);

        QPainter p(this);
        QRect r(10,10,100,100);
        p.setPen(pen);
        //r.moveCenter()
        p.drawEllipse(r);
        /*ellipse=new QGraphicsEllipseItem(10,10,100,100);
        scene.addItem(ellipse);
        ellipse->show();*/


        for(int i=0;i<edge_vect2.size();i++)
        {

            std::cerr<<edge_vect2[i].first<<" "<<edge_vect2[i].second<<std::endl;
            //Gabriel edges are coloured green
            scene.addItem(qline[i]);
            qline[i]->setLine(edge_vect2[i].first.x(),edge_vect2[i].first.y(),edge_vect2[i].second.x(),edge_vect2[i].second.y());
            qline[i]->show();
            //c=Point_2((edge_vect2[i].first.x()+edge_vect2[i].second.x())/2,(edge_vect2[i].first.y()+edge_vect2[i].second.y())/2);
            //Draw circle: Qt way, and it works
            /*double twopi=6.2830853071795865;
            double rad=57.2957795130823209;
            double dist=std::sqrt(std::pow(edge_vect2[i].first.x()-edge_vect2[i].second.x(),2)+std::pow(edge_vect2[i].first.y()-edge_vect2[i].second.y(),2));
            double m=(edge_vect2[i].second.y()-edge_vect2[i].first.y())/(edge_vect2[i].second.x()-edge_vect2[i].first.x());
            double theta= std::atan(m);
            if(edge_vect2[i].first.y()==edge_vect2[i].second.y())
                ellipse[i]=new QGraphicsEllipseItem(edge_vect2[i].first.x(),edge_vect2[i].first.y()-(dist/2),dist,dist);
            else if(edge_vect2[i].first.x()==edge_vect2[i].second.x())
                ellipse[i]=new QGraphicsEllipseItem(edge_vect2[i].second.x()-(dist/2),edge_vect2[i].second.y(),dist,dist);
            else
            {
                if(theta<0)
                {
                    //theta+=twopi;
                    //theta*=rad;
                    ellipse[i]=new QGraphicsEllipseItem(edge_vect2[i].second.x()-(dist/2),edge_vect2[i].second.y()-(dist),dist,dist);
                    std::cerr<<"If 1"<<std::endl;
                    std::cerr<<theta<<std::endl;
                    //std::cerr<<edge_vect2[i].first<<" "<<edge_vect2[i].second<<std::endl;
                }
                else
                {

                    ellipse[i]=new QGraphicsEllipseItem(edge_vect2[i].first.x()-(dist),edge_vect2[i].first.y()-(dist/2),dist,dist);
                    std::cerr<<"If 3"<<std::endl;
                    std::cerr<<theta<<std::endl;
                }
             }

            //double m=(edge_vect2[i].first.y())/(edge_vect2[i].first.x());

            //theta=theta+60;


            //ellipse[i]->setStartAngle(theta);
            //transform.rotate(theta);
            //ellipse[i]->setTransform(transform);
            //ellipse[i]->setRotation(theta);

            //ellipse[i]=new QGraphicsEllipseItem();
            //std::cerr<<edge_vect2[i].first<<" "<<edge_vect2[i].second;
            //double dist=std::sqrt(std::pow(edge_vect2[i].first.x()-edge_vect2[i].second.x(),2)+std::pow(edge_vect2[i].first.y()-edge_vect2[i].second.y(),2));


            scene.addItem(ellipse[i]);
            ellipse[i]->show();
            //draw_circle(c,edge_vect2[i].first);*/


        }
    }else{
        for(int i=0;i<edge_vect2.size();i++)
        {
            scene.removeItem(qline[i]);
            //scene.removeItem(ellipse[i]);
        }

    }

}

void
MainWindow::clear_DS()
{
    d_points.clear();
    g_points1.clear();
    g_points2.clear();
    edge_vect.clear();
    edge_vect2.clear();

}

void
MainWindow::on_actionPlay_toggled(bool checked)
{

    //Velocity is defined for every points
    for(int i=vel_vect.size();i<edge_vect.size();i++)
        vel_vect.push_back(std::make_pair(0,0));

    if(checked)
    {
        m_size=0;
        //set is introduced for storing points
        for(int i=0;i<edge_vect.size();i++)
        {
            scene.removeItem(qline1[i]);
            m_points.insert(std::make_pair(edge_vect.at(i).first.x(),edge_vect.at(i).first.y()));
            m_points.insert(std::make_pair(edge_vect.at(i).second.x(),edge_vect.at(i).second.y()));

        }

        std::cerr<<"Points"<<std::endl;

        //Points are plotted using ellipses
        for(auto itr=m_points.begin();itr!=m_points.end();itr++)
        {
            pairs p=*itr;
            std::cerr<<p.first<<" "<<p.second<<std::endl;
            move[m_size]=new QGraphicsEllipseItem(p.first,p.second,1,1);
            scene.addItem(move[m_size]);
            m_size++;
        }
        /*int j=0;
        for(int i=0;i<edge_vect.size();i++)
        {
            move[j]=new QGraphicsEllipseItem(edge_vect.at(i).first.x(),edge_vect.at(i).first.y(),1,1);
            scene.addItem(move[i]);
            move[j+1]=new QGraphicsEllipseItem(edge_vect.at(i).second.x(),edge_vect.at(i).second.y(),1,1);
            scene.addItem(move[j+1]);
            j=j+2;
        }*/
        //Animation defined
        for(int i=0;i<m_size;i++)
        {
            timer[i]=new QTimeLine(5000);
            timer[i]->setFrameRange(0,200);
            anim[i]=new QGraphicsItemAnimation;
            anim[i]->setItem(move[i]);
            anim[i]->setTimeLine(timer[i]);
            for(int j=0;j<200;++j)
                anim[i]->setPosAt(j/200.0,QPointF(j,j));
        }

        for(int i=0;i<m_size;i++)
            timer[i]->start();

        /*QGraphicsEllipseItem *move1=new QGraphicsEllipseItem(-88,-40,1,1);
        QGraphicsEllipseItem *move2=new QGraphicsEllipseItem(-68,-20,1,1);




        QTimeLine *timer1=new QTimeLine(5000);
        timer1->setFrameRange(0,200);

        QTimeLine *timer2=new QTimeLine(3000);
        timer1->setFrameRange(0,200);

        QGraphicsItemAnimation *anim1=new QGraphicsItemAnimation;
        anim1->setItem(move1);
        anim1->setTimeLine(timer1);

        QGraphicsItemAnimation *anim2=new QGraphicsItemAnimation;
        anim2->setItem(move2);
        anim2->setTimeLine(timer2);

        for(int i=0;i<200;++i)
            anim1->setPosAt(i/200.0,QPointF(i,i));

        for(int i=0;i<200;++i)
            anim2->setPosAt(i/200.0,QPointF(i,i));

        scene.addItem(move1);
        scene.addItem(move2);
        view->show();
        timer1->start();
        timer2->start();*/

        std::cerr<<"m_size: "<<m_size<<std::endl;
    }
    else
    {

        clear_DS();
        //std::cerr<<"m_size: "<<m_size<<std::endl;
        //Animation is stopped
        for(int i=0;i<m_size;i++)
        {
            timer[i]->stop();
            //std::cerr<<move[i]->x()<<" "<<move[i]->y()<<std::endl;
            //p=new Point_2(move[i]->x(),move[i]->y());
        }
        int i=0;
        //d_points is defined with updated values
        std::cerr<<"updated point for Delaunay\n"<<std::endl;
        for(auto itr=m_points.begin();itr!=m_points.end();itr++,i++)
        {
            pairs ptr=*itr;
            //std::cerr<<p.first<<" "<<p.second<<std::endl;
            K::Point_2 p(ptr.first+move[i]->x(),ptr.second+move[i]->y());
            std::cerr<<p<<std::endl;
            d_points.push_back(p);
            g_points1.push_back(p);
            g_points2.push_back(p);

        }
        //New Delaunauy created
        dt.insert(d_points.begin(), d_points.end());
        compute_gabriel();
    }
}
void
MainWindow::on_actionVelocity_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                            tr("Open Points file"),
                            ".");
    if(! fileName.isEmpty()){
      open_velocity(fileName);
    }
}
void
MainWindow::on_actionShowVoronoi_toggled(bool checked)
{
  vgi->setVisible(checked);
}


void
MainWindow::on_actionClear_triggered()
{
  dt.clear();
  Q_EMIT( changed());
}


void
MainWindow::on_actionInsertRandomPoints_triggered()
{
  QRectF rect = CGAL::Qt::viewportsBbox(&scene);
  CGAL::Qt::Converter<K> convert;
  Iso_rectangle_2 isor = convert(rect);
  CGAL::Random_points_in_iso_rectangle_2<Point_2> pg((isor.min)(), (isor.max)());
  bool ok = false;

  const int number_of_points =
    QInputDialog::getInt(this,
                             tr("Number of random points"),
                             tr("Enter number of random points"),
                 100,
                 0,
                 (std::numeric_limits<int>::max)(),
                 1,
                 &ok);

  if(!ok) {
    return;
  }

  // wait cursor
  QApplication::setOverrideCursor(Qt::WaitCursor);
  std::vector<Point_2> points;
  points.reserve(number_of_points);
  for(int i = 0; i < number_of_points; ++i){
    points.push_back(*pg);

  }

  std::cerr << "Delaunay " << std::endl;
  dt.insert(points.begin(), points.end());
  // default cursor
  QApplication::restoreOverrideCursor();
  Q_EMIT( changed());
}


void
MainWindow::on_actionLoadPoints_triggered()
{

  QString fileName = QFileDialog::getOpenFileName(this,
                          tr("Open Points file"),
                          ".");
  if(! fileName.isEmpty()){
    open(fileName);
  }

}

void
MainWindow::compute_gabriel()
{
    Point_2 c;
    bool flag=false;
    Delaunay::Vertex_handle v1;
    Delaunay::Vertex_handle v2;


        for(int i=0;i<g_points1.size();i++)
        {
            for(int jj=0;jj<g_points2.size();jj++)
            {
            	//vertex handlers are introduced
                v1=dt.insert(Point(g_points1.at(i)));
                v2=dt.insert(Point(g_points2.at(jj)));
                //edge validity is checked
                bool check=dt.is_edge(v1,v2);
                    if(check)
                    {
                    	//Edges are identified
                        edge_vect.push_back(std::make_pair(g_points1.at(i),g_points2.at(jj)));
                    }
            }
            g_points2.erase(g_points2.begin());
        }
        std::cerr<<"Edges:\n"<<std::endl;
        for(int i=0;i<edge_vect.size();i++)
            std::cerr<<edge_vect[i].first<<" "<<edge_vect[i].second<<"\n";
        for(int i=0;i<edge_vect.size();i++)
        {
            Point_2 a=edge_vect[i].first;
            Point_2 b=edge_vect[i].second;
		
	    //Gabriel check
            double x1=a.x();double y1=a.y();double x2=b.x();double y2=b.y();
            double dist=std::sqrt(std::pow(x1-x2,2)+std::pow(y1-y2,2));
            c=Point_2((a.x()+b.x())/2,(a.y()+b.y())/2);
            for(int k=0;k<g_points1.size();)
            {
                if(g_points1.at(k)==a||g_points1.at(k)==b)
                {
                  k++;
                }
                else
                {
                    x2=g_points1.at(k).x();
                    y2=g_points1.at(k).y();
                    double dist2=std::sqrt(std::pow(c.x()-x2,2)+std::pow(c.y()-y2,2));
                    if(dist2<=dist/2)
                    {
                        flag=true;
                        break;
                    }
                    k++;
                }
            }
            if(!flag)
                edge_vect2.push_back(std::make_pair(a,b));

            flag=false;

        }

        std::cerr<<"Number of Gabriel Edges:"<<edge_vect2.size()<<std::endl;
        dt.clear();
        //std::cerr<<"cp 1"<<std::endl;
        for(int i=0;i<edge_vect.size();i++)
        {
            scene.addItem(qline1[i]);
            qline1[i]->setLine(edge_vect[i].first.x(),edge_vect[i].first.y(),edge_vect[i].second.x(),edge_vect[i].second.y());
            qline1[i]->show();
        }
        //std::cerr<<"cp 2"<<std::endl;
}

void
MainWindow::open_velocity(QString filename)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    std::ifstream ifs(qPrintable(filename));
    double p;

    std::vector<double> vel;
    while(ifs >> p) {
      // ignore whatever comes after x and y
      ifs.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
      //points.push_back(p);
      //vel_vect.push_back(std::make_pair(p.x(),p.y()));
      vel.push_back(p);
    }


    for(int i=0;i<vel.size();)
    {
        vel_vect.push_back(std::make_pair(vel.at(i),vel.at(i+1)));
        i=i+2;
    }
}
void
MainWindow::open(QString fileName)
{
  // wait cursor

  QApplication::setOverrideCursor(Qt::WaitCursor);
  std::ifstream ifs(qPrintable(fileName));
  K::Point_2 p;
  //std::vector<K::Point_2> points;
  while(ifs >> p) {
    // ignore whatever comes after x and y
    ifs.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    d_points.push_back(p);
    g_points1.push_back(p);
    g_points2.push_back(p);
  }
  //int x=g_points.size();


  dt.insert(d_points.begin(), d_points.end());
  compute_gabriel();
  // default cursor
  QApplication::restoreOverrideCursor();
  this->addToRecentFiles(fileName);
  actionRecenter->trigger();
  Q_EMIT( changed());

}

void
MainWindow::on_actionSavePoints_triggered()
{
  QString fileName = QFileDialog::getSaveFileName(this,
                          tr("Save points"),
                          ".");
  if(! fileName.isEmpty()){
    std::ofstream ofs(qPrintable(fileName));
    for(Delaunay::Finite_vertices_iterator
          vit = dt.finite_vertices_begin(),
          end = dt.finite_vertices_end();
        vit!= end; ++vit)
    {
      ofs << vit->point() << std::endl;
    }
  }
}


void
MainWindow::on_actionRecenter_triggered()
{
  this->graphicsView->setSceneRect(dgi->boundingRect());
  this->graphicsView->fitInView(dgi->boundingRect(), Qt::KeepAspectRatio);
}


#include "Delaunay_triangulation_2.moc"
#include <CGAL/Qt/resources.h>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  app.setOrganizationDomain("geometryfactory.com");
  app.setOrganizationName("GeometryFactory");
  app.setApplicationName("Delaunay_triangulation_2 demo");

  // Import resources from libCGAL (QT5).
  CGAL_QT_INIT_RESOURCES;

  MainWindow mainWindow;
  mainWindow.show();

  QStringList args = app.arguments();
  args.removeAt(0);
  Q_FOREACH(QString filename, args) {
    mainWindow.open(filename);
  }

  return app.exec();
}

