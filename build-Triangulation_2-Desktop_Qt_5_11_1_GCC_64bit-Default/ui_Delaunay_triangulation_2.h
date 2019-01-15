/********************************************************************************
** Form generated from reading UI file 'Delaunay_triangulation_2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELAUNAY_TRIANGULATION_2_H
#define UI_DELAUNAY_TRIANGULATION_2_H

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

class Ui_Delaunay_triangulation_2
{
public:
    QAction *actionAbout;
    QAction *actionAboutCGAL;
    QAction *actionExport_SVG;
    QAction *actionQuit;
    QAction *actionInsertRandomPoints;
    QAction *actionMovingPoint;
    QAction *actionInsertPoint;
    QAction *actionClear;
    QAction *actionShowVoronoi;
    QAction *actionShowGabriel;
    QAction *actionShowDelaunay;
    QAction *actionLoadPoints;
    QAction *actionSavePoints;
    QAction *actionCircumcenter;
    QAction *actionRecenter;
    QAction *actionShowConflictZone;
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

    void setupUi(QMainWindow *Delaunay_triangulation_2)
    {
        if (Delaunay_triangulation_2->objectName().isEmpty())
            Delaunay_triangulation_2->setObjectName(QStringLiteral("Delaunay_triangulation_2"));
        Delaunay_triangulation_2->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/cgal/logos/cgal_icon"), QSize(), QIcon::Normal, QIcon::Off);
        Delaunay_triangulation_2->setWindowIcon(icon);
        actionAbout = new QAction(Delaunay_triangulation_2);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutCGAL = new QAction(Delaunay_triangulation_2);
        actionAboutCGAL->setObjectName(QStringLiteral("actionAboutCGAL"));
        actionExport_SVG = new QAction(Delaunay_triangulation_2);
        actionExport_SVG->setObjectName(QStringLiteral("actionExport_SVG"));
        actionQuit = new QAction(Delaunay_triangulation_2);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionInsertRandomPoints = new QAction(Delaunay_triangulation_2);
        actionInsertRandomPoints->setObjectName(QStringLiteral("actionInsertRandomPoints"));
        actionMovingPoint = new QAction(Delaunay_triangulation_2);
        actionMovingPoint->setObjectName(QStringLiteral("actionMovingPoint"));
        actionMovingPoint->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/cgal/Actions/icons/moving_point.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMovingPoint->setIcon(icon1);
        actionInsertPoint = new QAction(Delaunay_triangulation_2);
        actionInsertPoint->setObjectName(QStringLiteral("actionInsertPoint"));
        actionInsertPoint->setCheckable(true);
        actionInsertPoint->setChecked(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/cgal/Input/inputPoint.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsertPoint->setIcon(icon2);
        actionClear = new QAction(Delaunay_triangulation_2);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/cgal/fileToolbar/fileNew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionShowVoronoi = new QAction(Delaunay_triangulation_2);
        actionShowVoronoi->setObjectName(QStringLiteral("actionShowVoronoi"));
        actionShowVoronoi->setCheckable(true);
        actionShowVoronoi->setChecked(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/cgal/Triangulation_2/Voronoi_diagram_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowVoronoi->setIcon(icon4);
        actionShowGabriel = new QAction(Delaunay_triangulation_2);
        actionShowGabriel->setObjectName(QStringLiteral("actionShowGabriel"));
        actionShowGabriel->setCheckable(true);
        actionShowGabriel->setChecked(false);
        actionShowGabriel->setIcon(icon4);
        actionShowDelaunay = new QAction(Delaunay_triangulation_2);
        actionShowDelaunay->setObjectName(QStringLiteral("actionShowDelaunay"));
        actionShowDelaunay->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/cgal/Actions/icons/triangulation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowDelaunay->setIcon(icon5);
        actionLoadPoints = new QAction(Delaunay_triangulation_2);
        actionLoadPoints->setObjectName(QStringLiteral("actionLoadPoints"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/cgal/fileToolbar/fileOpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadPoints->setIcon(icon6);
        actionSavePoints = new QAction(Delaunay_triangulation_2);
        actionSavePoints->setObjectName(QStringLiteral("actionSavePoints"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/cgal/fileToolbar/fileSave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSavePoints->setIcon(icon7);
        actionCircumcenter = new QAction(Delaunay_triangulation_2);
        actionCircumcenter->setObjectName(QStringLiteral("actionCircumcenter"));
        actionCircumcenter->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/cgal/Actions/icons/circumcenter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircumcenter->setIcon(icon8);
        actionRecenter = new QAction(Delaunay_triangulation_2);
        actionRecenter->setObjectName(QStringLiteral("actionRecenter"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/cgal/Input/zoom-best-fit"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecenter->setIcon(icon9);
        actionShowConflictZone = new QAction(Delaunay_triangulation_2);
        actionShowConflictZone->setObjectName(QStringLiteral("actionShowConflictZone"));
        actionShowConflictZone->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/cgal/Actions/icons/conflict_zone.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowConflictZone->setIcon(icon10);
        centralwidget = new QWidget(Delaunay_triangulation_2);
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

        Delaunay_triangulation_2->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Delaunay_triangulation_2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Delaunay_triangulation_2->setStatusBar(statusbar);
        fileToolBar = new QToolBar(Delaunay_triangulation_2);
        fileToolBar->setObjectName(QStringLiteral("fileToolBar"));
        Delaunay_triangulation_2->addToolBar(Qt::TopToolBarArea, fileToolBar);
        toolBar = new QToolBar(Delaunay_triangulation_2);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Delaunay_triangulation_2->addToolBar(Qt::TopToolBarArea, toolBar);
        menubar = new QMenuBar(Delaunay_triangulation_2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        Delaunay_triangulation_2->setMenuBar(menubar);

        fileToolBar->addAction(actionClear);
        fileToolBar->addAction(actionLoadPoints);
        fileToolBar->addAction(actionSavePoints);
        fileToolBar->addAction(actionShowGabriel);
        toolBar->addAction(actionInsertPoint);
        toolBar->addAction(actionMovingPoint);
        toolBar->addAction(actionShowGabriel);
        toolBar->addAction(actionCircumcenter);
        toolBar->addAction(actionShowConflictZone);
        toolBar->addSeparator();
        toolBar->addAction(actionShowDelaunay);
        toolBar->addAction(actionShowVoronoi);
        toolBar->addSeparator();
        toolBar->addAction(actionRecenter);
        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionClear);
        menuFile->addAction(actionShowGabriel);
        menuFile->addAction(actionLoadPoints);
        menuFile->addAction(actionSavePoints);
        menuFile->addAction(actionExport_SVG);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionInsertRandomPoints);
        menuTools->addAction(actionInsertPoint);
        menuTools->addAction(actionMovingPoint);
        menuTools->addAction(actionCircumcenter);
        menuTools->addAction(actionShowConflictZone);
        menuTools->addSeparator();
        menuTools->addAction(actionShowDelaunay);
        menuTools->addAction(actionShowVoronoi);
        menuTools->addSeparator();
        menuTools->addAction(actionRecenter);
        menuTools->addAction(actionShowGabriel);

        retranslateUi(Delaunay_triangulation_2);

        QMetaObject::connectSlotsByName(Delaunay_triangulation_2);
    } // setupUi

    void retranslateUi(QMainWindow *Delaunay_triangulation_2)
    {
        Delaunay_triangulation_2->setWindowTitle(QApplication::translate("Delaunay_triangulation_2", "CGAL Delaunay Triangulation", nullptr));
        actionAbout->setText(QApplication::translate("Delaunay_triangulation_2", "&About", nullptr));
        actionAboutCGAL->setText(QApplication::translate("Delaunay_triangulation_2", "About &CGAL", nullptr));
        actionExport_SVG->setText(QApplication::translate("Delaunay_triangulation_2", "&Export SVG...", nullptr));
        actionQuit->setText(QApplication::translate("Delaunay_triangulation_2", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("Delaunay_triangulation_2", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionInsertRandomPoints->setText(QApplication::translate("Delaunay_triangulation_2", "&Insert random points", nullptr));
#ifndef QT_NO_SHORTCUT
        actionInsertRandomPoints->setShortcut(QApplication::translate("Delaunay_triangulation_2", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionMovingPoint->setText(QApplication::translate("Delaunay_triangulation_2", "&Simulate insertion", nullptr));
#ifndef QT_NO_TOOLTIP
        actionMovingPoint->setToolTip(QApplication::translate("Delaunay_triangulation_2", "Simulate Insertion", "The comment"));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionMovingPoint->setStatusTip(QApplication::translate("Delaunay_triangulation_2", "Move mouse with left button pressed to see where point would be inserted", "and its comment"));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        actionMovingPoint->setWhatsThis(QApplication::translate("Delaunay_triangulation_2", "whats this", "what"));
#endif // QT_NO_WHATSTHIS
        actionInsertPoint->setText(QApplication::translate("Delaunay_triangulation_2", "&Insert Point", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInsertPoint->setToolTip(QApplication::translate("Delaunay_triangulation_2", "Insert Point", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionInsertPoint->setStatusTip(QApplication::translate("Delaunay_triangulation_2", "Left: Insert vtx", nullptr));
#endif // QT_NO_STATUSTIP
        actionClear->setText(QApplication::translate("Delaunay_triangulation_2", "&Clear", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClear->setShortcut(QApplication::translate("Delaunay_triangulation_2", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowVoronoi->setText(QApplication::translate("Delaunay_triangulation_2", "Show &Voronoi Diagram", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShowVoronoi->setShortcut(QApplication::translate("Delaunay_triangulation_2", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowGabriel->setText(QApplication::translate("Delaunay_triangulation_2", "Show &Gabriel Edges", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShowGabriel->setShortcut(QApplication::translate("Delaunay_triangulation_2", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowDelaunay->setText(QApplication::translate("Delaunay_triangulation_2", "Show &Delaunay Triangulation", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShowDelaunay->setShortcut(QApplication::translate("Delaunay_triangulation_2", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoadPoints->setText(QApplication::translate("Delaunay_triangulation_2", "&Load Points...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoadPoints->setShortcut(QApplication::translate("Delaunay_triangulation_2", "Ctrl+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionSavePoints->setText(QApplication::translate("Delaunay_triangulation_2", "&Save Points...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSavePoints->setShortcut(QApplication::translate("Delaunay_triangulation_2", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionCircumcenter->setText(QApplication::translate("Delaunay_triangulation_2", "&Circumcenter", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCircumcenter->setToolTip(QApplication::translate("Delaunay_triangulation_2", "Draw circumcenter", nullptr));
#endif // QT_NO_TOOLTIP
        actionRecenter->setText(QApplication::translate("Delaunay_triangulation_2", "Re&center the viewport", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRecenter->setShortcut(QApplication::translate("Delaunay_triangulation_2", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowConflictZone->setText(QApplication::translate("Delaunay_triangulation_2", "Show Conflict Zone", nullptr));
        fileToolBar->setWindowTitle(QApplication::translate("Delaunay_triangulation_2", "File Tools", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Delaunay_triangulation_2", "Visualization Tools", nullptr));
        menuFile->setTitle(QApplication::translate("Delaunay_triangulation_2", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("Delaunay_triangulation_2", "&Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Delaunay_triangulation_2", "&Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Delaunay_triangulation_2: public Ui_Delaunay_triangulation_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELAUNAY_TRIANGULATION_2_H
