/********************************************************************************
** Form generated from reading UI file 'Constrained_Delaunay_triangulation_2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSTRAINED_DELAUNAY_TRIANGULATION_2_H
#define UI_CONSTRAINED_DELAUNAY_TRIANGULATION_2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Constrained_Delaunay_triangulation_2
{
public:
    QAction *actionAbout;
    QAction *actionAboutCGAL;
    QAction *actionQuit;
    QAction *actionInsertRandomPoints;
    QAction *actionInsertPolyline;
    QAction *actionClear;
    QAction *actionShowVoronoi;
    QAction *actionShowDelaunay;
    QAction *actionLoadConstraints;
    QAction *actionSaveConstraints;
    QAction *actionCircumcenter;
    QAction *actionRecenter;
    QAction *actionMakeGabrielConform;
    QAction *actionMakeDelaunayConform;
    QAction *actionMakeDelaunayMesh;
    QAction *actionMakeLipschitzDelaunayMesh;
    QAction *actionShow_constrained_edges;
    QAction *actionShow_faces_in_domain;
    QAction *actionShow_voronoi_edges;
    QAction *actionShow_blind_faces;
    QAction *actionTagBlindFaces;
    QAction *actionLloyd_optimization;
    QAction *actionInsertSeeds_OnOff;
    QAction *actionShow_seeds;
    QAction *actionShowTriangulationInDomain;
    QAction *actionShowVertices;
    QAction *actionExport_SVG;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QStatusBar *statusbar;
    QToolBar *fileToolBar;
    QToolBar *toolBar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;

    void setupUi(QMainWindow *Constrained_Delaunay_triangulation_2)
    {
        if (Constrained_Delaunay_triangulation_2->objectName().isEmpty())
            Constrained_Delaunay_triangulation_2->setObjectName(QStringLiteral("Constrained_Delaunay_triangulation_2"));
        Constrained_Delaunay_triangulation_2->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/cgal/logos/cgal_icon"), QSize(), QIcon::Normal, QIcon::Off);
        Constrained_Delaunay_triangulation_2->setWindowIcon(icon);
        actionAbout = new QAction(Constrained_Delaunay_triangulation_2);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutCGAL = new QAction(Constrained_Delaunay_triangulation_2);
        actionAboutCGAL->setObjectName(QStringLiteral("actionAboutCGAL"));
        actionQuit = new QAction(Constrained_Delaunay_triangulation_2);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionInsertRandomPoints = new QAction(Constrained_Delaunay_triangulation_2);
        actionInsertRandomPoints->setObjectName(QStringLiteral("actionInsertRandomPoints"));
        actionInsertPolyline = new QAction(Constrained_Delaunay_triangulation_2);
        actionInsertPolyline->setObjectName(QStringLiteral("actionInsertPolyline"));
        actionInsertPolyline->setCheckable(true);
        actionInsertPolyline->setChecked(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/cgal/Input/inputPolyline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsertPolyline->setIcon(icon1);
        actionClear = new QAction(Constrained_Delaunay_triangulation_2);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/cgal/fileToolbar/fileNew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon2);
        actionShowVoronoi = new QAction(Constrained_Delaunay_triangulation_2);
        actionShowVoronoi->setObjectName(QStringLiteral("actionShowVoronoi"));
        actionShowVoronoi->setCheckable(true);
        actionShowVoronoi->setChecked(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/cgal/Triangulation_2/Voronoi_diagram_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowVoronoi->setIcon(icon3);
        actionShowVoronoi->setVisible(false);
        actionShowDelaunay = new QAction(Constrained_Delaunay_triangulation_2);
        actionShowDelaunay->setObjectName(QStringLiteral("actionShowDelaunay"));
        actionShowDelaunay->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/cgal/Actions/icons/constrained_triangulation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowDelaunay->setIcon(icon4);
        actionLoadConstraints = new QAction(Constrained_Delaunay_triangulation_2);
        actionLoadConstraints->setObjectName(QStringLiteral("actionLoadConstraints"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/cgal/fileToolbar/fileOpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadConstraints->setIcon(icon5);
        actionSaveConstraints = new QAction(Constrained_Delaunay_triangulation_2);
        actionSaveConstraints->setObjectName(QStringLiteral("actionSaveConstraints"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/cgal/fileToolbar/fileSave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveConstraints->setIcon(icon6);
        actionCircumcenter = new QAction(Constrained_Delaunay_triangulation_2);
        actionCircumcenter->setObjectName(QStringLiteral("actionCircumcenter"));
        actionCircumcenter->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/cgal/Actions/icons/circumcenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircumcenter->setIcon(icon7);
        actionRecenter = new QAction(Constrained_Delaunay_triangulation_2);
        actionRecenter->setObjectName(QStringLiteral("actionRecenter"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/cgal/Input/zoom-best-fit"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecenter->setIcon(icon8);
        actionMakeGabrielConform = new QAction(Constrained_Delaunay_triangulation_2);
        actionMakeGabrielConform->setObjectName(QStringLiteral("actionMakeGabrielConform"));
        actionMakeDelaunayConform = new QAction(Constrained_Delaunay_triangulation_2);
        actionMakeDelaunayConform->setObjectName(QStringLiteral("actionMakeDelaunayConform"));
        actionMakeDelaunayMesh = new QAction(Constrained_Delaunay_triangulation_2);
        actionMakeDelaunayMesh->setObjectName(QStringLiteral("actionMakeDelaunayMesh"));
        actionMakeLipschitzDelaunayMesh = new QAction(Constrained_Delaunay_triangulation_2);
        actionMakeLipschitzDelaunayMesh->setObjectName(QStringLiteral("actionMakeLipschitzDelaunayMesh"));
        actionShow_constrained_edges = new QAction(Constrained_Delaunay_triangulation_2);
        actionShow_constrained_edges->setObjectName(QStringLiteral("actionShow_constrained_edges"));
        actionShow_constrained_edges->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/cgal/Actions/icons/constrained_triangulation_show_constraints.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_constrained_edges->setIcon(icon9);
        actionShow_faces_in_domain = new QAction(Constrained_Delaunay_triangulation_2);
        actionShow_faces_in_domain->setObjectName(QStringLiteral("actionShow_faces_in_domain"));
        actionShow_faces_in_domain->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/cgal/Actions/icons/constrained_triangulation_show_in_domain.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_faces_in_domain->setIcon(icon10);
        actionShow_voronoi_edges = new QAction(Constrained_Delaunay_triangulation_2);
        actionShow_voronoi_edges->setObjectName(QStringLiteral("actionShow_voronoi_edges"));
        actionShow_voronoi_edges->setCheckable(true);
        actionShow_blind_faces = new QAction(Constrained_Delaunay_triangulation_2);
        actionShow_blind_faces->setObjectName(QStringLiteral("actionShow_blind_faces"));
        actionShow_blind_faces->setCheckable(true);
        actionTagBlindFaces = new QAction(Constrained_Delaunay_triangulation_2);
        actionTagBlindFaces->setObjectName(QStringLiteral("actionTagBlindFaces"));
        actionLloyd_optimization = new QAction(Constrained_Delaunay_triangulation_2);
        actionLloyd_optimization->setObjectName(QStringLiteral("actionLloyd_optimization"));
        actionInsertSeeds_OnOff = new QAction(Constrained_Delaunay_triangulation_2);
        actionInsertSeeds_OnOff->setObjectName(QStringLiteral("actionInsertSeeds_OnOff"));
        actionInsertSeeds_OnOff->setCheckable(true);
        actionShow_seeds = new QAction(Constrained_Delaunay_triangulation_2);
        actionShow_seeds->setObjectName(QStringLiteral("actionShow_seeds"));
        actionShow_seeds->setCheckable(true);
        actionShowTriangulationInDomain = new QAction(Constrained_Delaunay_triangulation_2);
        actionShowTriangulationInDomain->setObjectName(QStringLiteral("actionShowTriangulationInDomain"));
        actionShowTriangulationInDomain->setCheckable(true);
        actionShowVertices = new QAction(Constrained_Delaunay_triangulation_2);
        actionShowVertices->setObjectName(QStringLiteral("actionShowVertices"));
        actionShowVertices->setCheckable(true);
        actionShowVertices->setChecked(true);
        actionExport_SVG = new QAction(Constrained_Delaunay_triangulation_2);
        actionExport_SVG->setObjectName(QStringLiteral("actionExport_SVG"));
        centralwidget = new QWidget(Constrained_Delaunay_triangulation_2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setFocusPolicy(Qt::StrongFocus);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        Constrained_Delaunay_triangulation_2->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Constrained_Delaunay_triangulation_2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Constrained_Delaunay_triangulation_2->setStatusBar(statusbar);
        fileToolBar = new QToolBar(Constrained_Delaunay_triangulation_2);
        fileToolBar->setObjectName(QStringLiteral("fileToolBar"));
        Constrained_Delaunay_triangulation_2->addToolBar(Qt::TopToolBarArea, fileToolBar);
        toolBar = new QToolBar(Constrained_Delaunay_triangulation_2);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Constrained_Delaunay_triangulation_2->addToolBar(Qt::TopToolBarArea, toolBar);
        menubar = new QMenuBar(Constrained_Delaunay_triangulation_2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        Constrained_Delaunay_triangulation_2->setMenuBar(menubar);

        fileToolBar->addAction(actionClear);
        fileToolBar->addAction(actionLoadConstraints);
        fileToolBar->addAction(actionSaveConstraints);
        toolBar->addAction(actionInsertPolyline);
        toolBar->addSeparator();
        toolBar->addAction(actionShowDelaunay);
        toolBar->addAction(actionShow_constrained_edges);
        toolBar->addAction(actionShowVoronoi);
        toolBar->addAction(actionShow_faces_in_domain);
        toolBar->addAction(actionCircumcenter);
        toolBar->addSeparator();
        toolBar->addAction(actionRecenter);
        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionClear);
        menuFile->addAction(actionLoadConstraints);
        menuFile->addAction(actionSaveConstraints);
        menuFile->addAction(actionExport_SVG);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionInsertRandomPoints);
        menuTools->addAction(actionRecenter);
        menuTools->addSeparator();
        menuTools->addAction(actionInsertPolyline);
        menuTools->addAction(actionInsertSeeds_OnOff);
        menuTools->addSeparator();
        menuTools->addAction(actionShowVertices);
        menuTools->addAction(actionShowDelaunay);
        menuTools->addAction(actionShowVoronoi);
        menuTools->addAction(actionShowTriangulationInDomain);
        menuTools->addAction(actionShow_constrained_edges);
        menuTools->addAction(actionShow_voronoi_edges);
        menuTools->addAction(actionShow_faces_in_domain);
        menuTools->addAction(actionShow_seeds);
        menuTools->addAction(actionCircumcenter);
        menuTools->addSeparator();
        menuTools->addAction(actionShow_blind_faces);
        menuTools->addAction(actionTagBlindFaces);
        menuTools->addSeparator();
        menuTools->addAction(actionMakeGabrielConform);
        menuTools->addAction(actionMakeDelaunayConform);
        menuTools->addAction(actionMakeDelaunayMesh);
        menuTools->addAction(actionMakeLipschitzDelaunayMesh);
        menuTools->addSeparator();
        menuTools->addAction(actionLloyd_optimization);

        retranslateUi(Constrained_Delaunay_triangulation_2);

        QMetaObject::connectSlotsByName(Constrained_Delaunay_triangulation_2);
    } // setupUi

    void retranslateUi(QMainWindow *Constrained_Delaunay_triangulation_2)
    {
        Constrained_Delaunay_triangulation_2->setWindowTitle(QApplication::translate("Constrained_Delaunay_triangulation_2", "CGAL Constrained Delaunay Triangulation", nullptr));
        actionAbout->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "&About", nullptr));
        actionAboutCGAL->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "About &CGAL", nullptr));
        actionQuit->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionInsertRandomPoints->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Insert random points", nullptr));
#ifndef QT_NO_SHORTCUT
        actionInsertRandomPoints->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionInsertPolyline->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Insert Polyline", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInsertPolyline->setToolTip(QApplication::translate("Constrained_Delaunay_triangulation_2", "Insert Point or Polyline", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionInsertPolyline->setStatusTip(QApplication::translate("Constrained_Delaunay_triangulation_2", "Left: Insert vtx | Right: Final vtx | Del: Delete vtx", nullptr));
#endif // QT_NO_STATUSTIP
        actionClear->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Clear", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClear->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowVoronoi->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Show &Voronoi Diagram", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShowVoronoi->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowDelaunay->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Show &triangulation", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShowDelaunay->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+T", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoadConstraints->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Load...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoadConstraints->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionSaveConstraints->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Save...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSaveConstraints->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionCircumcenter->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Circumcenter", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCircumcenter->setToolTip(QApplication::translate("Constrained_Delaunay_triangulation_2", "Draw circumcenter", nullptr));
#endif // QT_NO_TOOLTIP
        actionRecenter->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Re&center the viewport", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRecenter->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionMakeGabrielConform->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Make Gabriel conform", nullptr));
        actionMakeDelaunayConform->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Make Delaunay conform", nullptr));
        actionMakeDelaunayMesh->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Make Delaunay mesh...", nullptr));
        actionMakeLipschitzDelaunayMesh->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Make Lipschitz Delaunay mesh...", nullptr));
        actionShow_constrained_edges->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Show &constrained edges", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShow_constrained_edges->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionShow_faces_in_domain->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Show &faces in domain", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShow_faces_in_domain->setShortcut(QApplication::translate("Constrained_Delaunay_triangulation_2", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionShow_voronoi_edges->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Show Voronoi edges (CVD)", nullptr));
        actionShow_blind_faces->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Show blind faces (for CVD)", nullptr));
        actionTagBlindFaces->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Tag blind faces", nullptr));
        actionLloyd_optimization->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Lloyd optimization", nullptr));
        actionInsertSeeds_OnOff->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Insert seeds (on/off)", nullptr));
        actionShow_seeds->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Show seeds", nullptr));
        actionShowTriangulationInDomain->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Show triangulation in domain only", nullptr));
        actionShowVertices->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "Show vertices", nullptr));
        actionExport_SVG->setText(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Export SVG...", nullptr));
        fileToolBar->setWindowTitle(QApplication::translate("Constrained_Delaunay_triangulation_2", "File Tools", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Constrained_Delaunay_triangulation_2", "Visualization Tools", nullptr));
        menuFile->setTitle(QApplication::translate("Constrained_Delaunay_triangulation_2", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Constrained_Delaunay_triangulation_2", "&Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Constrained_Delaunay_triangulation_2: public Ui_Constrained_Delaunay_triangulation_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSTRAINED_DELAUNAY_TRIANGULATION_2_H
