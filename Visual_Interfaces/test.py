import sys
from PySide6.QtWidgets import (
    QApplication, QWidget, QLabel, QPushButton,
    QVBoxLayout, QLineEdit
)
from PySide6.QtCore import Qt


class CuteWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Cute App")
        self.setFixedSize(300, 200)

        # Widgets
        title = QLabel("Hello ♡")
        title.setAlignment(Qt.AlignCenter)

        self.input = QLineEdit()
        self.input.setPlaceholderText("Type something cute")

        button = QPushButton("Click me")
        button.clicked.connect(self.on_click)

        # Layout
        layout = QVBoxLayout()
        layout.addWidget(title)
        layout.addWidget(self.input)
        layout.addWidget(button)
        layout.setSpacing(12)

        self.setLayout(layout)

        # Style
        self.setStyleSheet("""
            QWidget {
                background-color: #f7eefe;
                font-family: Arial;
            }
            QLabel {
                font-size: 20px;
                font-weight: bold;
                color: #5a3d7a;
            }
            QLineEdit {
                padding: 8px;
                border-radius: 10px;
                border: 1px solid #c8b6e2;
                background-color: white;
            }
            QPushButton {
                padding: 8px;
                border-radius: 12px;
                background-color: #d8b4f8;
                color: #3d2b52;
                font-weight: bold;
            }
            QPushButton:hover {
                background-color: #c89af3;
            }
        """)

    def on_click(self):
        text = self.input.text()
        self.input.setText(f"{text} ♡")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = CuteWindow()
    window.show()
    sys.exit(app.exec())
