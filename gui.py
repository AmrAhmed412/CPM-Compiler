import sys
import subprocess
import qdarkstyle
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QTextEdit, QPushButton
from PyQt5.QtCore import Qt
class CompilerGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        self.setWindowTitle('Compiler GUI')
        # Layout
        layout = QVBoxLayout()
        # Code input
        self.code_label = QLabel('Enter Code Snippet:')
        layout.addWidget(self.code_label)
        self.code_text = QTextEdit()
        layout.addWidget(self.code_text)
        # Compile button
        self.compile_button = QPushButton('Compile', self)
        self.compile_button.clicked.connect(self.compile_code)
        layout.addWidget(self.compile_button)
        # Symbol table output
        self.symbol_label = QLabel('Symbol Table:')
        layout.addWidget(self.symbol_label)
        self.symbol_text = QTextEdit()
        self.symbol_text.setReadOnly(True)
        layout.addWidget(self.symbol_text)
        # Quads output
        self.quads_label = QLabel('Quads:')
        layout.addWidget(self.quads_label)
        self.quads_text = QTextEdit()
        self.quads_text.setReadOnly(True)
        self.setStyleSheet(qdarkstyle.load_stylesheet_pyqt5())
        layout.addWidget(self.quads_text)
        self.setLayout(layout)
        self.setGeometry(100, 100, 800, 600)
    def compile_code(self):
        # Read code snippet from input field
        code_snippet = self.code_text.toPlainText().strip()
        # Write code snippet to a temporary file
        with open('input_code.txt', 'w') as f:
            f.write(code_snippet)
        
        try:
            # print("yalla")
            # Execute a.exe with the input file
            process = subprocess.Popen(['a.exe'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            # Read input from a file and pass it to the subprocess
            with open('input_code.txt', 'r') as f:
                input_data = f.read()
            # print(input_data)
            # Communicate with the subprocess, sending input from the file
            output, error = process.communicate(input=input_data)
            # print("eddyy")
            # print(error)
            # Read the results from the output files
            symbol_table = self.read_file('symbol_table.txt')
            quads = self.read_file('quads.txt')
            # Display the contents of the files in the respective text fields
            self.symbol_text.setPlainText(symbol_table)
            self.quads_text.setPlainText(quads)
        except subprocess.CalledProcessError as e:
            self.symbol_text.setPlainText("Error: Failed to execute a.exe")
            self.quads_text.setPlainText("")
    def read_file(self, file_path):
        try:
            with open(file_path, 'r') as f:
                return f.read()
        except FileNotFoundError:
            return f"Error: {file_path} not found."
if __name__ == '__main__':
    app = QApplication(sys.argv)
    gui = CompilerGUI()
    gui.show()
    sys.exit(app.exec_())