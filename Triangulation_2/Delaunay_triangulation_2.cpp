#include <fstream>
#include <thread>
#include <chrono>


// CGAL headers
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Qt/Converter.h>
#include <CGAL/point_generators_2.h>
#include <CGAL/squared_distance_2.h>
#include <CGAL/Circle_2.h>
#include <CGAL/enum.h>
#include <CGAL/number_utils.h>


// Qt headers
#include <QtGui>
#include <QString>
#include <QActionGroup>
#include <QFileDialog>
#include <QInputDialog>
#include <QLineF>
#include <QPointF>

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

class MainWindow :
  public CGAL::Qt::DemosMainWindow,
  public Ui::Delaunay_triangulation_2
{
  Q_OBJECT

private:
  Delaunay dt;
  QGraphicsScene scene;
  QGraphicsLineItem *qline[50];
  QPointF p1,p2;
  Point_2 x,y;
  int j=0;

  std::vector<Point_2> g_points1;
  std::vector<Point_2> g_points2;

  std::vector<std::pair<Point_2,Point_2>> edge_vect;
  std::vector<std::pair<Point_2,Point_2>> edge_vect2;

  CGAL::Qt::TriangulationGraphicsItem<Delaunay> * dgi;
  CGAL::Qt::VoronoiGraphicsItem<Delaunay> * vgi;
  CGAL::Qt::TriangulationGraphicsItem<Delaunay> * gg;




  CGAL::Qt::TriangulationMovingPoint<Delaunay> * mp;
  CGAL::Qt::TriangulationConflictZone<Delaunay> * cz;
  CGAL::Qt::TriangulationRemoveVertex<Delaunay> * trv;
  CGAL::Qt::TriangulationPointInputAndConflictZone<Delaunay> * pi;
  CGAL::Qt::TriangulationCircumcircle<Delaunay> *tcc;

public:
  MainWindow();

public Q_SLOTS:

  void processInput(CGAL::Object o);

  void on_actionMovingPoint_toggled(bool checked);

  void on_actionShowConflictZone_toggled(bool checked);

  void on_actionCircumcenter_toggled(bool checked);

  void on_actionShowDelaunay_toggled(bool checked);

  void on_actionShowVoronoi_toggled(bool checked);

  void on_actionShowGabriel_toggled(bool checked);

  void on_actionInsertPoint_toggled(bool checked);

  void on_actionInsertRandomPoints_triggered();

  void on_actionLoadPoints_triggered();

  void on_actionSavePoints_triggered();

  void on_actionClear_triggered();

  void on_actionRecenter_triggered();

  virtual void open(QString fileName);

Q_SIGNALS:
  void changed();
};


MainWindow::MainWindow()
  : DemosMainWindow()
{
  setupUi(this);

  for(int i=0;i<50;i++)
  {
      qline[i]=new QGraphicsLineItem();
      qline[i]->setPen(QPen(Qt::darkRed,0,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
      qline[i]->hide();
  }

  this->graphicsView->setAcceptDrops(false);

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

void
MainWindow::on_actionShowGabriel_toggled(bool checked)
{
    //CGAL::Qt::Converter<K> convert(Point_2);
    Point_2 c;
    bool flag=false;
    Delaunay::Vertex_handle v1;
    Delaunay::Vertex_handle v2;
    if(checked){
        //j=0;
        //qreal x1=250,x2=150,y1=600,y2=450;
        //std::cerr<<"Inside Gabriel"<<std::endl;
        //gg->setEdgesPen(QPen(Qt::green,0,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
        //scene.addLine(x1,y1,x2,y2,QPen(Qt::green,0,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
        //scene.addItem(gg);
        //scene.addItem(qline);
        //int x=points.size();
        //std::cerr<<"Inside Gabriel:"<<x<<std::endl;

        for(int i=0;i<g_points1.size();i++)
        {
            for(int j=0;j<g_points2.size();j++)
            {



            /*for(j=0;j<i;j++)
            {
            std::cerr<<g_points.at(i).x()<<g_points.at(i).y()<<"\n"<<g_points.at(i+1).x()<<g_points.at(i+1).y()<<j<<std::endl;
            QPointF x=convert(g_points.at(i));
            scene.addItem(qline[j]);
            qline[j]->setLine(g_points.at(i).x(),g_points.at(i).y(),g_points.at(i+1).x(),g_points.at(i+1).y());
            qline[j]->show();*/

            v1=dt.insert(Point(g_points1.at(i)));
            v2=dt.insert(Point(g_points2.at(j)));
            bool check=dt.is_edge(v1,v2);
                if(check)
                {
                    edge_vect.push_back(std::make_pair(g_points1.at(i),g_points2.at(j)));
                }

            }
            g_points2.erase(g_points2.begin());
        }
        for(int i=0;i<edge_vect.size();i++)
        {
            Point_2 a=edge_vect[i].first;
            Point_2 b=edge_vect[i].second;
            //std::cerr<<a<<" "<<b<<std::endl;
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
                    if(dist2<=dist)
                    {
                        flag=true;
                        break;
                    }
                    k++;
                }
            }
            if(!flag)
                edge_vect2.push_back(std::make_pair(a,b));
            //double c=CGAL::squared_distance(a,b);
            //std::cerr<<a<<" "<<b<<":"<<c<<std::endl;
            //std::cerr<<dist/2<<std::endl;
            //CGAL::Orientation ori=CGAL::COUNTERCLOCKWISE;
            //CGAL::Circle_2<K> c1=CGAL::Circle_2(a,b,ori);
            flag=false;

        }
        dt.clear();
        dt.insert(g_points1.begin(),g_points1.end());
        for(int i=0;i<edge_vect2.size();i++)
        {
            //v1=dt.insert(Point(edge_vect2[i].first));
            //v2=dt.insert(Point(edge_vect2[i].second));
            //dt.remove(v1);
            //dt.remove(v2);


            std::cerr<<edge_vect2[i].first<<edge_vect2[i].second<<std::endl;
            scene.addItem(qline[i]);
            qline[i]->setLine(edge_vect2[i].first.x(),edge_vect2[i].first.y(),edge_vect2[i].second.x(),edge_vect2[i].second.y());
            qline[i]->show();
        }
    }else{
        for(int i=0;i<edge_vect2.size();i++)
        {
            scene.removeItem(qline[i]);
        }
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
MainWindow::open(QString fileName)
{
  // wait cursor

  QApplication::setOverrideCursor(Qt::WaitCursor);
  std::ifstream ifs(qPrintable(fileName));
  K::Point_2 p;
  std::vector<K::Point_2> points;
  while(ifs >> p) {
    // ignore whatever comes after x and y
    ifs.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    points.push_back(p);
    g_points1.push_back(p);
    g_points2.push_back(p);
  }
  //int x=g_points.size();


  dt.insert(points.begin(), points.end());

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
