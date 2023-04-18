# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'MainWindow.ui'
##
## Created by: Qt User Interface Compiler version 6.5.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QAction, QBrush, QColor, QConicalGradient,
    QCursor, QFont, QFontDatabase, QGradient,
    QIcon, QImage, QKeySequence, QLinearGradient,
    QPainter, QPalette, QPixmap, QRadialGradient,
    QTransform)
from PySide6.QtWidgets import (QApplication, QGroupBox, QHBoxLayout, QLabel,
    QMainWindow, QMenu, QMenuBar, QPushButton,
    QRadioButton, QScrollArea, QSizePolicy, QSlider,
    QSpacerItem, QSpinBox, QStatusBar, QVBoxLayout,
    QWidget)

from CustomLabel import CustomLabel
from HistoryWidget import HistoryWidget

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(901, 613)
        self.actionOpen = QAction(MainWindow)
        self.actionOpen.setObjectName(u"actionOpen")
        self.actionSave = QAction(MainWindow)
        self.actionSave.setObjectName(u"actionSave")
        self.actionReverse = QAction(MainWindow)
        self.actionReverse.setObjectName(u"actionReverse")
        self.actionExit = QAction(MainWindow)
        self.actionExit.setObjectName(u"actionExit")
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.horizontalLayout = QHBoxLayout(self.centralwidget)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.scrollArea = QScrollArea(self.centralwidget)
        self.scrollArea.setObjectName(u"scrollArea")
        sizePolicy = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.scrollArea.sizePolicy().hasHeightForWidth())
        self.scrollArea.setSizePolicy(sizePolicy)
        self.scrollArea.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.scrollArea.setWidgetResizable(True)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollAreaWidgetContents.setObjectName(u"scrollAreaWidgetContents")
        self.scrollAreaWidgetContents.setGeometry(QRect(0, -449, 188, 988))
        self.verticalLayout = QVBoxLayout(self.scrollAreaWidgetContents)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.groupBox_4 = QGroupBox(self.scrollAreaWidgetContents)
        self.groupBox_4.setObjectName(u"groupBox_4")
        sizePolicy1 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.groupBox_4.sizePolicy().hasHeightForWidth())
        self.groupBox_4.setSizePolicy(sizePolicy1)
        self.verticalLayout_6 = QVBoxLayout(self.groupBox_4)
        self.verticalLayout_6.setObjectName(u"verticalLayout_6")
        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.rb_HSL = QRadioButton(self.groupBox_4)
        self.rb_HSL.setObjectName(u"rb_HSL")
        self.rb_HSL.setChecked(True)

        self.horizontalLayout_2.addWidget(self.rb_HSL)

        self.rb_HSV = QRadioButton(self.groupBox_4)
        self.rb_HSV.setObjectName(u"rb_HSV")

        self.horizontalLayout_2.addWidget(self.rb_HSV)


        self.verticalLayout_6.addLayout(self.horizontalLayout_2)

        self.label_3 = QLabel(self.groupBox_4)
        self.label_3.setObjectName(u"label_3")

        self.verticalLayout_6.addWidget(self.label_3)

        self.horizontalLayout_6 = QHBoxLayout()
        self.horizontalLayout_6.setObjectName(u"horizontalLayout_6")
        self.hs_Hue = QSlider(self.groupBox_4)
        self.hs_Hue.setObjectName(u"hs_Hue")
        self.hs_Hue.setMinimum(0)
        self.hs_Hue.setMaximum(360)
        self.hs_Hue.setOrientation(Qt.Horizontal)

        self.horizontalLayout_6.addWidget(self.hs_Hue)

        self.sb_Hue = QSpinBox(self.groupBox_4)
        self.sb_Hue.setObjectName(u"sb_Hue")
        self.sb_Hue.setMaximum(360)

        self.horizontalLayout_6.addWidget(self.sb_Hue)


        self.verticalLayout_6.addLayout(self.horizontalLayout_6)

        self.label_4 = QLabel(self.groupBox_4)
        self.label_4.setObjectName(u"label_4")

        self.verticalLayout_6.addWidget(self.label_4)

        self.horizontalLayout_7 = QHBoxLayout()
        self.horizontalLayout_7.setObjectName(u"horizontalLayout_7")
        self.hs_Saturation = QSlider(self.groupBox_4)
        self.hs_Saturation.setObjectName(u"hs_Saturation")
        self.hs_Saturation.setMinimum(0)
        self.hs_Saturation.setMaximum(255)
        self.hs_Saturation.setOrientation(Qt.Horizontal)

        self.horizontalLayout_7.addWidget(self.hs_Saturation)

        self.sb_Saturation = QSpinBox(self.groupBox_4)
        self.sb_Saturation.setObjectName(u"sb_Saturation")
        self.sb_Saturation.setMaximum(255)

        self.horizontalLayout_7.addWidget(self.sb_Saturation)


        self.verticalLayout_6.addLayout(self.horizontalLayout_7)

        self.l_Light_Value = QLabel(self.groupBox_4)
        self.l_Light_Value.setObjectName(u"l_Light_Value")

        self.verticalLayout_6.addWidget(self.l_Light_Value)

        self.horizontalLayout_8 = QHBoxLayout()
        self.horizontalLayout_8.setObjectName(u"horizontalLayout_8")
        self.hs_Light_Value = QSlider(self.groupBox_4)
        self.hs_Light_Value.setObjectName(u"hs_Light_Value")
        self.hs_Light_Value.setMinimum(0)
        self.hs_Light_Value.setMaximum(255)
        self.hs_Light_Value.setOrientation(Qt.Horizontal)

        self.horizontalLayout_8.addWidget(self.hs_Light_Value)

        self.sb_Light_Value = QSpinBox(self.groupBox_4)
        self.sb_Light_Value.setObjectName(u"sb_Light_Value")
        self.sb_Light_Value.setMaximum(255)

        self.horizontalLayout_8.addWidget(self.sb_Light_Value)


        self.verticalLayout_6.addLayout(self.horizontalLayout_8)

        self.label = QLabel(self.groupBox_4)
        self.label.setObjectName(u"label")

        self.verticalLayout_6.addWidget(self.label)

        self.horizontalLayout_4 = QHBoxLayout()
        self.horizontalLayout_4.setObjectName(u"horizontalLayout_4")
        self.hs_Brightness = QSlider(self.groupBox_4)
        self.hs_Brightness.setObjectName(u"hs_Brightness")
        self.hs_Brightness.setMinimum(-100)
        self.hs_Brightness.setMaximum(100)
        self.hs_Brightness.setOrientation(Qt.Horizontal)

        self.horizontalLayout_4.addWidget(self.hs_Brightness)

        self.sp_Brightness = QSpinBox(self.groupBox_4)
        self.sp_Brightness.setObjectName(u"sp_Brightness")
        self.sp_Brightness.setMinimum(-100)
        self.sp_Brightness.setMaximum(100)

        self.horizontalLayout_4.addWidget(self.sp_Brightness)


        self.verticalLayout_6.addLayout(self.horizontalLayout_4)

        self.label_2 = QLabel(self.groupBox_4)
        self.label_2.setObjectName(u"label_2")

        self.verticalLayout_6.addWidget(self.label_2)

        self.horizontalLayout_5 = QHBoxLayout()
        self.horizontalLayout_5.setObjectName(u"horizontalLayout_5")
        self.hs_Contrast = QSlider(self.groupBox_4)
        self.hs_Contrast.setObjectName(u"hs_Contrast")
        self.hs_Contrast.setMinimum(-100)
        self.hs_Contrast.setMaximum(100)
        self.hs_Contrast.setOrientation(Qt.Horizontal)

        self.horizontalLayout_5.addWidget(self.hs_Contrast)

        self.sb_Contrast = QSpinBox(self.groupBox_4)
        self.sb_Contrast.setObjectName(u"sb_Contrast")
        self.sb_Contrast.setMinimum(-100)
        self.sb_Contrast.setMaximum(100)

        self.horizontalLayout_5.addWidget(self.sb_Contrast)


        self.verticalLayout_6.addLayout(self.horizontalLayout_5)

        self.b_Apply = QPushButton(self.groupBox_4)
        self.b_Apply.setObjectName(u"b_Apply")

        self.verticalLayout_6.addWidget(self.b_Apply)


        self.verticalLayout.addWidget(self.groupBox_4)

        self.groupBox_2 = QGroupBox(self.scrollAreaWidgetContents)
        self.groupBox_2.setObjectName(u"groupBox_2")
        sizePolicy1.setHeightForWidth(self.groupBox_2.sizePolicy().hasHeightForWidth())
        self.groupBox_2.setSizePolicy(sizePolicy1)
        self.verticalLayout_3 = QVBoxLayout(self.groupBox_2)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.b_Negative = QPushButton(self.groupBox_2)
        self.b_Negative.setObjectName(u"b_Negative")

        self.verticalLayout_3.addWidget(self.b_Negative)

        self.b_Toning = QPushButton(self.groupBox_2)
        self.b_Toning.setObjectName(u"b_Toning")

        self.verticalLayout_3.addWidget(self.b_Toning)

        self.b_Grayscale = QPushButton(self.groupBox_2)
        self.b_Grayscale.setObjectName(u"b_Grayscale")

        self.verticalLayout_3.addWidget(self.b_Grayscale)

        self.b_Emboss = QPushButton(self.groupBox_2)
        self.b_Emboss.setObjectName(u"b_Emboss")

        self.verticalLayout_3.addWidget(self.b_Emboss)

        self.b_Sharpen = QPushButton(self.groupBox_2)
        self.b_Sharpen.setObjectName(u"b_Sharpen")

        self.verticalLayout_3.addWidget(self.b_Sharpen)

        self.b_BoxBlur = QPushButton(self.groupBox_2)
        self.b_BoxBlur.setObjectName(u"b_BoxBlur")

        self.verticalLayout_3.addWidget(self.b_BoxBlur)

        self.b_GaussianBlur = QPushButton(self.groupBox_2)
        self.b_GaussianBlur.setObjectName(u"b_GaussianBlur")

        self.verticalLayout_3.addWidget(self.b_GaussianBlur)

        self.b_Laplacian = QPushButton(self.groupBox_2)
        self.b_Laplacian.setObjectName(u"b_Laplacian")

        self.verticalLayout_3.addWidget(self.b_Laplacian)

        self.b_Prewitt = QPushButton(self.groupBox_2)
        self.b_Prewitt.setObjectName(u"b_Prewitt")

        self.verticalLayout_3.addWidget(self.b_Prewitt)

        self.b_SobelLeft = QPushButton(self.groupBox_2)
        self.b_SobelLeft.setObjectName(u"b_SobelLeft")

        self.verticalLayout_3.addWidget(self.b_SobelLeft)

        self.b_SobelRight = QPushButton(self.groupBox_2)
        self.b_SobelRight.setObjectName(u"b_SobelRight")

        self.verticalLayout_3.addWidget(self.b_SobelRight)

        self.b_SobelFull = QPushButton(self.groupBox_2)
        self.b_SobelFull.setObjectName(u"b_SobelFull")

        self.verticalLayout_3.addWidget(self.b_SobelFull)

        self.b_CustomFilter = QPushButton(self.groupBox_2)
        self.b_CustomFilter.setObjectName(u"b_CustomFilter")

        self.verticalLayout_3.addWidget(self.b_CustomFilter)


        self.verticalLayout.addWidget(self.groupBox_2)

        self.verticalSpacer = QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.verticalLayout.addItem(self.verticalSpacer)

        self.scrollArea.setWidget(self.scrollAreaWidgetContents)

        self.horizontalLayout.addWidget(self.scrollArea)

        self.verticalLayout_4 = QVBoxLayout()
        self.verticalLayout_4.setObjectName(u"verticalLayout_4")
        self.labelImage = CustomLabel(self.centralwidget)
        self.labelImage.setObjectName(u"labelImage")
        sizePolicy2 = QSizePolicy(QSizePolicy.Ignored, QSizePolicy.Ignored)
        sizePolicy2.setHorizontalStretch(1)
        sizePolicy2.setVerticalStretch(1)
        sizePolicy2.setHeightForWidth(self.labelImage.sizePolicy().hasHeightForWidth())
        self.labelImage.setSizePolicy(sizePolicy2)
        self.labelImage.setMinimumSize(QSize(100, 100))
        self.labelImage.setAlignment(Qt.AlignCenter)

        self.verticalLayout_4.addWidget(self.labelImage)

        self.groupBox_3 = QGroupBox(self.centralwidget)
        self.groupBox_3.setObjectName(u"groupBox_3")
        self.verticalLayout_5 = QVBoxLayout(self.groupBox_3)
        self.verticalLayout_5.setObjectName(u"verticalLayout_5")
        self.sa_History = HistoryWidget(self.groupBox_3)
        self.sa_History.setObjectName(u"sa_History")
        self.sa_History.setWidgetResizable(True)

        self.verticalLayout_5.addWidget(self.sa_History)


        self.verticalLayout_4.addWidget(self.groupBox_3)


        self.horizontalLayout.addLayout(self.verticalLayout_4)

        self.horizontalLayout.setStretch(1, 2)
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QStatusBar(MainWindow)
        self.statusbar.setObjectName(u"statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.menubar = QMenuBar(MainWindow)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 901, 25))
        self.menuFile = QMenu(self.menubar)
        self.menuFile.setObjectName(u"menuFile")
        self.menuPhoto = QMenu(self.menubar)
        self.menuPhoto.setObjectName(u"menuPhoto")
        MainWindow.setMenuBar(self.menubar)

        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuPhoto.menuAction())
        self.menuFile.addAction(self.actionOpen)
        self.menuFile.addAction(self.actionSave)
        self.menuFile.addAction(self.actionExit)
        self.menuPhoto.addAction(self.actionReverse)

        self.retranslateUi(MainWindow)
        self.actionExit.triggered.connect(MainWindow.close)
        self.hs_Brightness.valueChanged.connect(self.sp_Brightness.setValue)
        self.hs_Contrast.valueChanged.connect(self.sb_Contrast.setValue)
        self.hs_Hue.valueChanged.connect(self.sb_Hue.setValue)
        self.hs_Saturation.valueChanged.connect(self.sb_Saturation.setValue)
        self.hs_Light_Value.valueChanged.connect(self.sb_Light_Value.setValue)
        self.sb_Light_Value.valueChanged.connect(self.hs_Light_Value.setValue)
        self.sb_Saturation.valueChanged.connect(self.hs_Saturation.setValue)
        self.sb_Hue.valueChanged.connect(self.hs_Hue.setValue)
        self.sb_Contrast.valueChanged.connect(self.hs_Contrast.setValue)
        self.sp_Brightness.valueChanged.connect(self.hs_Brightness.setValue)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"Photolab", None))
        self.actionOpen.setText(QCoreApplication.translate("MainWindow", u"Open", None))
#if QT_CONFIG(shortcut)
        self.actionOpen.setShortcut(QCoreApplication.translate("MainWindow", u"Ctrl+O", None))
#endif // QT_CONFIG(shortcut)
        self.actionSave.setText(QCoreApplication.translate("MainWindow", u"Save", None))
#if QT_CONFIG(shortcut)
        self.actionSave.setShortcut(QCoreApplication.translate("MainWindow", u"Ctrl+S", None))
#endif // QT_CONFIG(shortcut)
        self.actionReverse.setText(QCoreApplication.translate("MainWindow", u"Reverse", None))
#if QT_CONFIG(shortcut)
        self.actionReverse.setShortcut(QCoreApplication.translate("MainWindow", u"Ctrl+Z", None))
#endif // QT_CONFIG(shortcut)
        self.actionExit.setText(QCoreApplication.translate("MainWindow", u"Exit", None))
#if QT_CONFIG(shortcut)
        self.actionExit.setShortcut(QCoreApplication.translate("MainWindow", u"Ctrl+Q", None))
#endif // QT_CONFIG(shortcut)
        self.groupBox_4.setTitle(QCoreApplication.translate("MainWindow", u"Color", None))
        self.rb_HSL.setText(QCoreApplication.translate("MainWindow", u"HSL", None))
        self.rb_HSV.setText(QCoreApplication.translate("MainWindow", u"HSV", None))
        self.label_3.setText(QCoreApplication.translate("MainWindow", u"Hue", None))
        self.label_4.setText(QCoreApplication.translate("MainWindow", u"Saturation", None))
        self.l_Light_Value.setText(QCoreApplication.translate("MainWindow", u"Light", None))
        self.label.setText(QCoreApplication.translate("MainWindow", u"Brightness", None))
        self.label_2.setText(QCoreApplication.translate("MainWindow", u"Contrast", None))
        self.b_Apply.setText(QCoreApplication.translate("MainWindow", u"Apply", None))
        self.groupBox_2.setTitle(QCoreApplication.translate("MainWindow", u"Filters", None))
        self.b_Negative.setText(QCoreApplication.translate("MainWindow", u"Negative", None))
        self.b_Toning.setText(QCoreApplication.translate("MainWindow", u"Toning", None))
        self.b_Grayscale.setText(QCoreApplication.translate("MainWindow", u"Grayscale", None))
        self.b_Emboss.setText(QCoreApplication.translate("MainWindow", u"Emboss", None))
        self.b_Sharpen.setText(QCoreApplication.translate("MainWindow", u"Sharpen", None))
        self.b_BoxBlur.setText(QCoreApplication.translate("MainWindow", u"Box Blur", None))
        self.b_GaussianBlur.setText(QCoreApplication.translate("MainWindow", u"Gaussian Blur", None))
        self.b_Laplacian.setText(QCoreApplication.translate("MainWindow", u"Laplacian Filter", None))
        self.b_Prewitt.setText(QCoreApplication.translate("MainWindow", u"Prewitt Filter", None))
        self.b_SobelLeft.setText(QCoreApplication.translate("MainWindow", u"Sobel Filter Left", None))
        self.b_SobelRight.setText(QCoreApplication.translate("MainWindow", u"Sobel Filter Right", None))
        self.b_SobelFull.setText(QCoreApplication.translate("MainWindow", u"Sobel Filter Full", None))
        self.b_CustomFilter.setText(QCoreApplication.translate("MainWindow", u"Custom Filter", None))
        self.labelImage.setText("")
        self.groupBox_3.setTitle(QCoreApplication.translate("MainWindow", u"History", None))
        self.menuFile.setTitle(QCoreApplication.translate("MainWindow", u"File", None))
        self.menuPhoto.setTitle(QCoreApplication.translate("MainWindow", u"Photo", None))
    # retranslateUi

