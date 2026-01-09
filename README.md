# VideoOCRApplication
This is a Qt/C++ desktop app that demonstrates a complete video‑to‑OCR pipeline using dialogs and a main window, built with CMake and standard Qt object‑oriented concepts. You can describe it as a small “Video OCR Application” that loads video frames, preprocesses them (monochrome) and prepares them for optical character recognition.[1]

## Full project description

- The **goal** is to provide a GUI where a user can open a video, view frames, convert them to monochrome, and then pass these processed frames to an OCR step.[1]
- The application is implemented in **C++ (90%)** with **CMake (10%)** for build configuration and uses Qt for all GUI and event handling.[1]
- The design separates responsibilities into a `MainWindow` and two dialogs (`MonochromeDialog` and `OcrDialog`), which makes the project easy to extend (for example, adding real Tesseract integration later).[1]

You can write in your README or project report:

> “VideoOCRApplication is a Qt‑based C++ desktop application that allows users to load a video, preview frames, apply monochrome preprocessing, and then forward processed frames to an OCR workflow using a dedicated OCR dialog. It is structured with a central `MainWindow` that coordinates video handling and two modular dialogs for image preprocessing and OCR output.”

## Files and what each does

| File                 | What it contains / does                                                                 |
|----------------------|-----------------------------------------------------------------------------------------|
| `CMakeLists.txt`     | CMake configuration for the project: sets C++ standard, finds Qt, defines the target, and adds all source files to the build.[1] |
| `main.cpp`           | Entry point of the application; creates `QApplication`, instantiates `MainWindow`, calls `show()` and starts the event loop.[1] |
| `mainwindow.h`       | Class declaration for `MainWindow`, including members for UI, actions, and slots to handle video, monochrome, and OCR dialogs.[1] |
| `mainwindow.cpp`     | Implementation of `MainWindow`: sets up menus/toolbars, connects signals/slots, opens videos, shows dialogs, and manages frame flow.[1] |
| `monochromedialog.h` | Class declaration for `MonochromeDialog`, defining UI elements and data to configure monochrome/threshold options.[1] |
| `monochromedialog.cpp` | Implementation of the monochrome dialog: initializes controls, reads user settings, and exposes them back to `MainWindow`.[1] |
| `ocrdialog.h`        | Class declaration for `OcrDialog`, including widgets to display recognized text and possibly options to trigger OCR.[1] |
| `ocrdialog.cpp`      | Implementation of the OCR dialog: builds the OCR UI, displays text results, and can call OCR logic or signal `MainWindow` to do so.[1] |

You can phrase this in a report as:

> “The project is organized into a `MainWindow` that manages core application logic and three pairs of header/source files (`mainwindow.*`, `monochromedialog.*`, `ocrdialog.*`) that encapsulate the main window and two dialogs. Build configuration is handled by `CMakeLists.txt`, and the application entry point is defined in `main.cpp`.”

## Concepts you have used

When you describe **what concepts you used**, mention both C++ and Qt:

- **Object‑oriented programming**  
  - Custom classes (`MainWindow`, `MonochromeDialog`, `OcrDialog`) encapsulate UI and logic, showing class design, encapsulation, and separation of concerns.[1]
  - Inheritance from Qt base classes (`QMainWindow`, `QDialog`) to reuse framework behavior and override or extend it.

- **Qt signals and slots (event‑driven programming)**  
  - Actions such as “Open Video”, “Monochrome Settings”, and “OCR” are connected to slots in `MainWindow` and the dialogs, implementing event‑driven architecture.[2][3]
  - Dialog buttons (OK/Cancel/Run OCR) emit signals or return values that control the main window’s behavior.

- **GUI design with Qt Widgets**  
  - Use of Qt widgets like menus, toolbars, dialogs, labels or video display widgets to create a desktop user interface.[3]
  - Modal dialogs (`MonochromeDialog`, `OcrDialog`) to configure processing and show results.

- **Modular design / separation of concerns**  
  - `MainWindow` handles application coordination and high‑level flow, while each dialog focuses on a single task: image preprocessing vs OCR results.[1]
  - This structure supports maintainability and future expansion (for example, adding advanced filters or connecting to a real OCR engine).

- **Build automation with CMake**  
  - `CMakeLists.txt` demonstrates using CMake to define a Qt C++ project, manage sources, and set language options.[1]

You can write in your documentation:

> “This project demonstrates object‑oriented design with C++ classes derived from Qt base classes, event‑driven programming with signals and slots, modular GUI design using dialogs and a main window, and build configuration using CMake.”

## How it works (step‑by‑step to describe)

You can describe the runtime flow like this:

1. **Application start**  
   - `main.cpp` creates a Qt application object, constructs `MainWindow`, and starts the event loop, showing the main window to the user.[1]

2. **User loads video**  
   - In `MainWindow`, a menu or toolbar action opens a file dialog so the user can choose a video file; the main window then starts reading and displaying its frames (via Qt Multimedia or OpenCV, depending on your implementation).

3. **User configures monochrome**  
   - Selecting the monochrome option opens `MonochromeDialog`, where the user adjusts grayscale or threshold settings and confirms them.  
   - `MainWindow` applies these settings when rendering or storing the current frame, producing a processed (monochrome) version ready for OCR.

4. **User runs OCR**  
   - The user opens `OcrDialog` and triggers OCR on the processed frame(s); the dialog displays recognized text in a text box and allows the user to copy or save it.

You can phrase it in your report as:

> “At runtime, the user first loads a video through the main window. The application captures frames and allows the user to open the monochrome dialog to configure preprocessing parameters. Once the frame is preprocessed, the user opens the OCR dialog, which runs OCR on the processed frame and displays the recognized text.”

If you paste your actual `mainwindow.cpp` / dialog code in the next message, a short code‑level explanation for each important function can be added so you can directly reuse it in documentation or viva.

[1](https://forum.qt.io/topic/162684/qt-creator-cmake-errors-after-downgrade-of-msvc-compiler)
[2](https://stackoverflow.com/questions/39643510/mainwindow-from-code-from-the-main-cpp-in-qt)
[3](https://radekp.github.io/qtmoko/api/mainwindows-mdi-mainwindow-cpp.html)
[4](https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/attachments/images/33115333/2d83bc46-e81c-4c95-8963-b77f2b841efd/image.jpg)
[5](https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/attachments/images/33115333/7c0de2c0-f037-401c-88ac-98d1fb684078/image.jpg)
[6](https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/attachments/images/33115333/6dbd65ef-b991-41b3-b99d-1a87a5436f90/image.jpg)
<img width="1165" height="975" alt="image" src="https://github.com/user-attachments/assets/0a3291c0-9213-4f15-9152-69b85c1695ba" />
<img width="1159" height="912" alt="image" src="https://github.com/user-attachments/assets/11433787-2c56-46bc-9fdb-864e91ce5a80" />
<img width="1141" height="945" alt="image" src="https://github.com/user-attachments/assets/28663e48-4731-4b46-a6b7-77ce5054df31" />


main.cpp creates and starts the Qt application, mainwindow.cpp implements the main UI and overall flow, and the two dialog .cpp files each handle a focused part of the video‑to‑OCR pipeline.
​

Below are descriptions you can copy into your README or project report.

main.cpp – application entry
Creates the QApplication object, which is required for any Qt Widgets GUI program.
​

Instantiates MainWindow (your main UI class), calls show() to display it, and then calls a.exec() to start the Qt event loop.
​

Does not contain business logic; its job is only to bootstrap the GUI and hand control to MainWindow.
​

Example description you can write:

main.cpp is the entry point of the application. It creates the Qt application object, constructs the MainWindow, shows it on screen, and starts the main event loop. All functional logic is delegated to the MainWindow class.

mainwindow.cpp – core UI and flow
Implements the MainWindow class that derives from QMainWindow and owns the central widgets, menus, and toolbars.
​

In the constructor, it sets up the UI (using ui->setupUi(this) if generated by Qt Designer), connects menu/toolbar actions to slots, and initializes members needed for video handling and dialogs.
​

Provides slots like “Open Video”, “Open Monochrome Dialog”, “Open OCR Dialog”, etc., which respond to user actions, update the video display, and open dialogs when needed.
​

Acts as the controller of the whole app: it knows the current video frame, passes data into dialogs, and receives settings or results back from them.
​

Example description:

mainwindow.cpp contains the implementation of the MainWindow class. It initializes the main GUI, sets up menus and toolbars, connects Qt signals and slots for user actions, handles video loading and frame display, and coordinates interaction with the Monochrome and OCR dialogs.

Concepts you show here:

Object‑oriented design (custom class derived from QMainWindow).
​

Event‑driven programming using Qt signals and slots for button/menu clicks and other events.
​

Separation of concerns: main window orchestrates, dialogs do specialized work.
​

monochromedialog.cpp – monochrome settings dialog
Implements MonochromeDialog, a class derived from QDialog that contains controls to configure monochrome / grayscale / threshold settings for frames.
​

In its constructor, it sets up the dialog UI elements (sliders, checkboxes, buttons) and initializes them with default or current values from the main window.
​

On “OK” or “Apply”, it reads the user’s chosen parameters and either:

stores them in member variables that MainWindow can query after exec(), or

emits a signal carrying a configuration struct or individual values back to MainWindow.
​

Example description:

monochromedialog.cpp implements the MonochromeDialog class, a Qt modal dialog used to configure image preprocessing options such as grayscale or threshold settings. It provides a simple UI for adjusting monochrome parameters and returns these settings to the MainWindow, which applies them to the video frames.

Concepts here:

Dialog‑based UI design with QDialog.
​

Passing configuration data between windows (either via return values or signals/slots).

Basic UX for preprocessing configuration (a “pre‑processing” stage in OCR terminology).
​

ocrdialog.cpp – OCR output dialog
Implements OcrDialog, another QDialog‑derived class that focuses on displaying OCR results and providing simple actions (e.g., run OCR, copy text).
​

Initializes UI elements such as a text area (QPlainTextEdit/QTextEdit) to show recognized text, and buttons to start OCR or close the dialog.
​

When OCR is triggered, it either:

calls OCR logic directly on the frame data passed from MainWindow, or

emits a signal so MainWindow runs OCR and then sets the resulting text into the dialog.
​

Example description:

ocrdialog.cpp implements the OcrDialog class, which is responsible for the OCR stage of the application. The dialog provides a text area to display recognized text from processed video frames and buttons to trigger OCR or copy/save the result. It receives processed image data from the MainWindow and presents the final OCR output to the user.

Concepts here:

Encapsulating a processing result view inside its own dialog.

Simple text‑handling UI with Qt widgets.

Mapping OCR workflow stages (pre‑processing → recognition → result display) into GUI components.
​

How to present “concepts used” for these four files
You can summarise everything in your report like this (adapt as needed):

main.cpp demonstrates the basic structure of a Qt Widgets application by creating the QApplication object and launching the MainWindow.

mainwindow.cpp shows object‑oriented and event‑driven programming using a class derived from QMainWindow that manages the main UI, video handling, and communication with dialogs through signals and slots.

monochromedialog.cpp applies modular design and dialog‑based UI patterns to encapsulate video frame preprocessing configuration (monochrome/threshold settings).

ocrdialog.cpp encapsulates the OCR stage, providing a dedicated dialog for running OCR on processed frames and displaying recognized text, which aligns with the typical OCR pipeline (preprocessing → recognition → post‑processing).



