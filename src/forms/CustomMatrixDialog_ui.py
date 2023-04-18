# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'CustomMatrixDialog.ui'
##
## Created by: Qt User Interface Compiler version 6.5.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QAbstractButton, QAbstractScrollArea, QAbstractSpinBox, QApplication,
    QDialog, QDialogButtonBox, QHBoxLayout, QHeaderView,
    QSizePolicy, QTableWidget, QTableWidgetItem, QVBoxLayout,
    QWidget)

from CustomSpinBox import CustomSpinBox

class Ui_CustomMatrixDialog(object):
    def setupUi(self, CustomMatrixDialog):
        if not CustomMatrixDialog.objectName():
            CustomMatrixDialog.setObjectName(u"CustomMatrixDialog")
        CustomMatrixDialog.resize(400, 300)
        self.verticalLayout = QVBoxLayout(CustomMatrixDialog)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.t_matrix = QTableWidget(CustomMatrixDialog)
        if (self.t_matrix.columnCount() < 3):
            self.t_matrix.setColumnCount(3)
        if (self.t_matrix.rowCount() < 3):
            self.t_matrix.setRowCount(3)
        __qtablewidgetitem = QTableWidgetItem()
        self.t_matrix.setItem(0, 0, __qtablewidgetitem)
        self.t_matrix.setObjectName(u"t_matrix")
        self.t_matrix.setVerticalScrollBarPolicy(Qt.ScrollBarAsNeeded)
        self.t_matrix.setHorizontalScrollBarPolicy(Qt.ScrollBarAsNeeded)
        self.t_matrix.setSizeAdjustPolicy(QAbstractScrollArea.AdjustToContents)
        self.t_matrix.setRowCount(3)
        self.t_matrix.setColumnCount(3)
        self.t_matrix.horizontalHeader().setCascadingSectionResizes(False)
        self.t_matrix.verticalHeader().setCascadingSectionResizes(False)

        self.verticalLayout.addWidget(self.t_matrix)

        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.sb_rows = CustomSpinBox(CustomMatrixDialog)
        self.sb_rows.setObjectName(u"sb_rows")
        self.sb_rows.setMinimum(1)
        self.sb_rows.setMaximum(15)
        self.sb_rows.setSingleStep(2)
        self.sb_rows.setStepType(QAbstractSpinBox.DefaultStepType)
        self.sb_rows.setValue(3)

        self.horizontalLayout.addWidget(self.sb_rows)

        self.sb_cols = CustomSpinBox(CustomMatrixDialog)
        self.sb_cols.setObjectName(u"sb_cols")
        self.sb_cols.setMinimum(1)
        self.sb_cols.setMaximum(15)
        self.sb_cols.setSingleStep(2)
        self.sb_cols.setValue(3)

        self.horizontalLayout.addWidget(self.sb_cols)

        self.buttonBox = QDialogButtonBox(CustomMatrixDialog)
        self.buttonBox.setObjectName(u"buttonBox")
        self.buttonBox.setOrientation(Qt.Horizontal)
        self.buttonBox.setStandardButtons(QDialogButtonBox.Cancel|QDialogButtonBox.Ok)

        self.horizontalLayout.addWidget(self.buttonBox)


        self.verticalLayout.addLayout(self.horizontalLayout)


        self.retranslateUi(CustomMatrixDialog)
        self.buttonBox.accepted.connect(CustomMatrixDialog.accept)
        self.buttonBox.rejected.connect(CustomMatrixDialog.reject)

        QMetaObject.connectSlotsByName(CustomMatrixDialog)
    # setupUi

    def retranslateUi(self, CustomMatrixDialog):
        CustomMatrixDialog.setWindowTitle(QCoreApplication.translate("CustomMatrixDialog", u"Dialog", None))

        __sortingEnabled = self.t_matrix.isSortingEnabled()
        self.t_matrix.setSortingEnabled(False)
        self.t_matrix.setSortingEnabled(__sortingEnabled)

        self.sb_rows.setPrefix(QCoreApplication.translate("CustomMatrixDialog", u"Rows: ", None))
        self.sb_cols.setPrefix(QCoreApplication.translate("CustomMatrixDialog", u"Cols: ", None))
    # retranslateUi

