# mp3-tag-reader
A command-line tool to view and edit ID3v2.3 tags in MP3 files using Advanced C.


# MP3 Tag Reader and Editor (ID3v2.3)

A command-line project written in **Advanced C** to **view and edit ID3v2.3 tags** (like Title, Artist, Album, Year, Genre, Comment) in `.mp3` files.

---

## 🎯 Features

* ✅ View metadata tags in MP3 files (Title, Artist, Album, etc.)
* ✅ Edit individual tags using command-line options
* ✅ Supports ID3 version 2.3
* ✅ Handles unknown frames gracefully
* ✅ Written with low-level binary file operations

---

## 🛠️ Tech Stack & Concepts Used

* C (Advanced concepts)
* File I/O: `fopen`, `fread`, `fwrite`
* Binary parsing & hex handling
* Structures & pointers
* Sync-safe integer logic
* Command-line argument parsing

---

## 📦 File Structure

```
mp3-tag-reader/
├── edit.c                # Code to edit tag frames
├── functions.c           # Helper logic for both view and edit
├── header.h              # Function declarations and common structs
├── help.c                # Help display logic
├── main.c                # Main CLI interface logic
├── sample.mp3            # Sample MP3 for testing
├── view.c                # Code to view tag content
├── MP3_Tag_Reader_Presentation.pptx   # Project presentation
└── README.md             # project overview and usage instructions 
---

## 🚀 Usage

### 🧾 View Mode

```bash
./a.out -v <file.mp3>
```

Displays tags: Title, Artist, Album, Year, Genre, Comment

### ✍️ Edit Mode

```bash
./a.out -e <file.mp3> <option> <new_value>
```

**Options:**

* `-t` Title
* `-a` Artist
* `-A` Album
* `-y` Year
* `-g` Genre
* `-c` Comment

### 🆘 Help Mode

```bash
./a.out -h
```

Displays command usage and tag options.

---

## 💡 Example

```bash
./a.out -v song.mp3
./a.out -e song.mp3 -t "New Song Title"
```

---

## 📂 Screenshots / PPT

Check out the full project explanation in the presentation:
📄 [`MP3_Tag_Reader_Presentation.pptx`](./MP3_Tag_Reader_Presentation.pptx)

---

## 🔮 Future Scope

* Support for ID3v2.4
* GUI version using Qt/GTK
* Batch editing support

---

## 👨‍💻 Author

**Bharath Kumar Gundralla**
🔗 [GitHub](https://github.com/Bharath-kumar-Gundralla)
🔗 [LinkedIn](https://www.linkedin.com/in/bharath-kumar-gundralla-1692a1317)

