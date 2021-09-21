import PyPDF2
import tkinter as tk
import tkmacosx as wid
from PIL import Image, ImageTk
from tkinter.filedialog import askopenfile

root = tk.Tk()

canvas = tk.Canvas(root, width=600, height=300)
canvas.grid(columnspan=3, rowspan=3)

logo = Image.open('/Users/miss_evgenia/Desktop/Coding/Projects/tkinter_project/logo.png')
logo = ImageTk.PhotoImage(logo)
logo_label = tk.Label(image=logo)
logo_label.image = logo
logo_label.grid(column=1, row=0)

#instructions
instructions = tk.Label(root, text='Select a PDF file on your computer to extract all its text', font="Raleway")
instructions.grid(columnspan=3, column=0, row=1)

def open_file():
    browse_text.set('loading...')
    file = askopenfile(parent=root, mode='rb', title='Choose a file',
                       filetypes=[('pdf', '*.pdf')])
    if file:
        read_pdf = PyPDF2.PdfFileReader(file)
        page = read_pdf.getPage(0)
        page_content = page.extractText()


        #text box
        text_box = tk.Text(root, height=10, width=50, padx=15, pady=15)
        text_box.insert(1.0, page_content)
        text_box.tag_configure('center', justify='center')
        text_box.tag_add('center', 1.0, 'end')
        text_box.grid(column=1, row=3)

        browse_text.set('Browse')

#browse button
browse_text = tk.StringVar()
browse_btn = wid.Button(root, textvariable=browse_text, command=lambda: open_file(),
                       font='Raleway', bg='#20BEBE', fg="white",
                       height=70, width=150)
browse_text.set('Browse')
browse_btn.grid(column=1, row=2)

canvas = tk.Canvas(root, width=600, height=250)
canvas.grid(columnspan=3)

root.mainloop()
