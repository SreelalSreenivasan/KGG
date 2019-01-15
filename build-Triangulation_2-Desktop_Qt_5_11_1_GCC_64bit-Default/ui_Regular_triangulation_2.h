/********************************************************************************
** Form generated from reading UI file 'Regular_triangulation_2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGULAR_TRIANGULATION_2_H
#define UI_REGULAR_TRIANGULATION_2_H

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

class Ui_Regular_triangulation_2
{
public:
    QAction *actionAbout;
    QAction *actionAboutCGAL;
    QAction *actionQuit;
    QAction *actionInsertRandomPoints;
    QAction *actionInsertPoint;
    QAction *actionClear;
    QAction *actionShowPowerdiagram;
    QAction *actionShowGabriel;
    QAction *actionShowRegular;
    QAction *actionLoadPoints;
    QAction *actionSavePoints;
    QAction *actionRecenter;
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

    void setupUi(QMainWindow *Regular_triangulation_2)
    {
        if (Regular_triangulation_2->objectName().isEmpty())
            Regular_triangulation_2->setObjectName(QStringLiteral("Regular_triangulation_2"));
        Regular_triangulation_2->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/cgal/logos/cgal_icon"), QSize(), QIcon::Normal, QIcon::Off);
        Regular_triangulation_2->setWindowIcon(icon);
        actionAbout = new QAction(Regular_triangulation_2);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutCGAL = new QAction(Regular_triangulation_2);
        actionAboutCGAL->setObjectName(QStringLiteral("actionAboutCGAL"));
        actionQuit = new QAction(Regular_triangulation_2);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionInsertRandomPoints = new QAction(Regular_triangulation_2);
        actionInsertRandomPoints->setObjectName(QStringLiteral("actionInsertRandomPoints"));
        actionInsertPoint = new QAction(Regular_triangulation_2);
        actionInsertPoint->setObjectName(QStringLiteral("actionInsertPoint"));
        actionInsertPoint->setCheckable(true);
        actionInsertPoint->setChecked(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/cgal/Input/inputPoint.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsertPoint->setIcon(icon1);
        actionClear = new QAction(Regular_triangulation_2);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/cgal/fileToolbar/fileNew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon2);
        actionShowPowerdiagram = new QAction(Regular_triangulation_2);
        actionShowPowerdiagram->setObjectName(QStringLiteral("actionShowPowerdiagram"));
        actionShowPowerdiagram->setCheckable(true);
        actionShowPowerdiagram->setChecked(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/cgal/Triangulation_2/Voronoi_diagram_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowPowerdiagram->setIcon(icon3);
        actionShowGabriel = new QAction(Regular_triangulation_2);
        actionShowGabriel->setObjectName(QStringLiteral("actionShowGabriel"));
        actionShowGabriel->setCheckable(true);
        actionShowGabriel->setChecked(false);
        actionShowGabriel->setIcon(icon3);
        actionShowRegular = new QAction(Regular_triangulation_2);
        actionShowRegular->setObjectName(QStringLiteral("actionShowRegular"));
        actionShowRegular->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/cgal/Triangulation_2/Delaunay_triangulation_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowRegular->setIcon(icon4);
        actionLoadPoints = new QAction(Regular_triangulation_2);
        actionLoadPoints->setObjectName(QStringLiteral("actionLoadPoints"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/cgal/fileToolbar/fileOpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadPoints->setIcon(icon5);
        actionSavePoints = new QAction(Regular_triangulation_2);
        actionSavePoints->setObjectName(QStringLiteral("actionSavePoints"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/cgal/fileToolbar/fileSave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSavePoints->setIcon(icon6);
        actionRecenter = new QAction(Regular_triangulation_2);
        actionRecenter->setObjectName(QStringLiteral("actionRecenter"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/cgal/Input/zoom-best-fit"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecenter->setIcon(icon7);
        centralwidget = new QWidget(Regular_triangulation_2);
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

        Regular_triangulation_2->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Regular_triangulation_2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Regular_triangulation_2->setStatusBar(statusbar);
        fileToolBar = new QToolBar(Regular_triangulation_2);
        fileToolBar->setObjectName(QStringLiteral("fileToolBar"));
        Regular_triangulation_2->addToolBar(Qt::TopToolBarArea, fileToolBar);
        toolBar = new QToolBar(Regular_triangulation_2);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Regular_triangulation_2->addToolBar(Qt::TopToolBarArea, toolBar);
        menubar = new QMenuBar(Regular_triangulation_2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 29));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        Regular_triangulation_2->setMenuBar(menubar);

        fileToolBar->addAction(actionClear);
        fileToolBar->addAction(actionLoadPoints);
        fileToolBar->addAction(actionSavePoints);
        toolBar->addAction(actionInsertPoint);
        toolBar->addAction(actionShowRegular);
        toolBar->addAction(actionShowPowerdiagram);
        toolBar->addAction(actionRecenter);
        toolBar->addAction(actionShowGabriel);
        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuTools->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionClear);
        menuFile->addAction(actionLoadPoints);
        menuFile->addAction(actionSavePoints);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionInsertRandomPoints);
        menuTools->addAction(actionInsertPoint);
        menuTools->addAction(actionShowRegular);
        menuTools->addAction(actionShowPowerdiagram);
        menuTools->addSeparator();
        menuTools->addAction(actionRecenter);

        retranslateUi(Regular_triangulation_2);

        QMetaObject::connectSlotsByName(Regular_triangulation_2);
    } // setupUi

    void retranslateUi(QMainWindow *Regular_triangulation_2)
    {
        Regular_triangulation_2->setWindowTitle(QApplication::translate("Regular_triangulation_2", "CGAL Regular Triangulation", nullptr));
        actionAbout->setText(QApplication::translate("Regular_triangulation_2", "&About", nullptr));
        actionAboutCGAL->setText(QApplication::translate("Regular_triangulation_2", "About &CGAL", nullptr));
        actionQuit->setText(QApplication::translate("Regular_triangulation_2", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("Regular_triangulation_2", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionInsertRandomPoints->setText(QApplication::translate("Regular_triangulation_2", "&Insert random points", nullptr));
#ifndef QT_NO_SHORTCUT
        actionInsertRandomPoints->setShortcut(QApplication::translate("Regular_triangulation_2", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionInsertPoint->setText(QApplication::translate("Regular_triangulation_2", "&Insert weighted point", nullptr));
#ifndef QT_NO_TOOLTIP
        actionInsertPoint->setToolTip(QApplication::translate("Regular_triangulation_2", "Insert weighted point", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionInsertPoint->setStatusTip(QApplication::translate("Regular_triangulation_2", "Left: Insert vtx", nullptr));
#endif // QT_NO_STATUSTIP
        actionClear->setText(QApplication::translate("Regular_triangulation_2", "&Clear", nullptr));
#ifndef QT_NO_SHORTCUT
        actionClear->setShortcut(QApplication::translate("Regular_triangulation_2", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowPowerdiagram->setText(QApplication::translate("Regular_triangulation_2", "Show &Voronoi Diagram", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShowPowerdiagram->setShortcut(QApplication::translate("Regular_triangulation_2", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowGabriel->setText(QApplication::translate("Regular_triangulation_2", "Show &Gabriel Edges", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShowGabriel->setShortcut(QApplication::translate("Regular_triangulation_2", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionShowRegular->setText(QApplication::translate("Regular_triangulation_2", "Show &Regular Triangulation", nullptr));
#ifndef QT_NO_SHORTCUT
        actionShowRegular->setShortcut(QApplication::translate("Regular_triangulation_2", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoadPoints->setText(QApplication::translate("Regular_triangulation_2", "&Load Points...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoadPoints->setShortcut(QApplication::translate("Regular_triangulation_2", "Ctrl+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionSavePoints->setText(QApplication::translate("Regular_triangulation_2", "&Save Points...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSavePoints->setShortcut(QApplication::translate("Regular_triangulation_2", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionRecenter->setText(QApplication::translate("Regular_triangulation_2", "Re&center the viewport", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRecenter->setShortcut(QApplication::translate("Regular_triangulation_2", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        fileToolBar->setWindowTitle(QApplication::translate("Regular_triangulation_2", "File Tools", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Regular_triangulation_2", "Visualization Tools", nullptr));
        menuFile->setTitle(QApplication::translate("Regular_triangulation_2", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("Regular_triangulation_2", "&Edit", nullptr));
        menuTools->setTitle(QApplication::translate("Regular_triangulation_2", "&Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Regular_triangulation_2: public Ui_Regular_triangulation_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGULAR_TRIANGULATION_2_H
