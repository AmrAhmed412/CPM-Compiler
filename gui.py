import sys
import subprocess
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QTextEdit, QPushButton, QFileDialog
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
        # Tokenized code output
        self.token_label = QLabel('Tokenized Code:')
        layout.addWidget(self.token_label)
        self.token_text = QTextEdit()
        self.token_text.setReadOnly(True)
        layout.addWidget(self.token_text)
        # Parsed code output
        self.parsed_label = QLabel('Parsed Code:')
        layout.addWidget(self.parsed_label)
        self.parsed_text = QTextEdit()
        self.parsed_text.setReadOnly(True)
        layout.addWidget(self.parsed_text)
        # Semantic analysis results output
        self.semantic_label = QLabel('Semantic Analysis Results:')
        layout.addWidget(self.semantic_label)
        self.semantic_text = QTextEdit()
        self.semantic_text.setReadOnly(True)
        layout.addWidget(self.semantic_text)
        self.setLayout(layout)
        self.setGeometry(100, 100, 800, 600)
    def compile_code(self):
        # Read code snippet from input field
        code_snippet = self.code_text.toPlainText().strip()
        code_snippet = self.code_text.toPlainText().strip()
        # Write code snippet to a temporary file
        with open('input_code.txt', 'w') as f:
            f.write(code_snippet)
        # Execute a.exe with the input file
        process = subprocess.run(['a.exe', 'input_code.txt'], capture_output=True, text=True)
        # Simulate the compilation process and write output to files
        tokenized_code = self.tokenize_code()
        parsed_code = self.parse_code()
        semantic_analysis_results = self.semantic_analysis()
        # Display the contents of the files in the respective text fields
        self.token_text.setPlainText(tokenized_code)
        self.parsed_text.setPlainText(parsed_code)
        self.semantic_text.setPlainText(semantic_analysis_results)
    def tokenize_code(self):
        with open("habal.txt", "r") as f:
            code = f.read()
        # Placeholder for actual tokenization process
        return "Tokenized code: " + code
    def parse_code(self):
        with open("habal2.txt", "r") as f:
            code = f.read()
        # Placeholder for actual parsing process
        return "Parsed code: " + code
    def semantic_analysis(self):
        with open("habal3.txt", "r") as f:
            code = f.read()
        # Placeholder for actual semantic analysis process
        return "Semantic analysis results: " + code
if __name__ == '__main__':
    app = QApplication(sys.argv)
    gui = CompilerGUI()
    gui.show()
    sys.exit(app.exec_())