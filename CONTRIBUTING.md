# Welcome to Login and Registration system contributing guide

Thank you for your interest in contributing to this project! We welcome
contributions from everyone. This document provides guidelines and
instructions to help you get started.

**Table of contents:**

- [Ways to contribute](#ways-to-contribute)
- [Getting started](#getting-started)
  - [Project structure](#project-structure)
- [Documenting](#documenting)
- [Style guidelines](#style-guidelines)
- [Development environment setup](#development-environment-setup)

## Ways to contribute

There are several ways to contribute to this project:

1. **Reporting bugs:**
   If you encounter any bugs or issues, please report them using the issue
   tracker.

2. **Fixing issues:**
   You can browse through the open issues and contribute by submitting pull
   requests.

3. **Suggesting enhancements:**
   If you have ideas for new features or improvements, feel free to suggest
   them using the issue tracker.

4. **Submitting code contributions:**
   If you have ideas for new features or improvements, feel free to make any
   necessary modifications and submit the changes. Make sure to follow
   project's coding style guidelines.

5. **Improving documentation:**
   If you find any areas of the documentation that can be improved, please
   submit a pull request.

6. **Sharing feedback:**
   Your feedback is important to us. If you have any suggestions or feedback
   regarding the project, please let us know.

7. **Help with issue triage:**
   You can contribute by review new issues, reproducing issues, asking for
   more details of an issue, categorize issues, prioritizing issues, etc.

8. **Answering questions and providing support to other contributors.**

## Getting started

If you are a new contributor, read the [README](README.md) to get the overview
of the project.

### Project structure

`(ignore)` Marked files or folders should not be included in the git
repository. They are used during the development. See
[Development environment setup](#development-environment-setup) to learn more
about them.

```
.
├── build/                      # Build files (ignore).
├── lib/                        # Libraries (ignore).
├── src/                        # Project source code (see src/README.md)
├── .clang-format               # Code formatting settings.
├── CMakeLists.txt              # Generates build files.
├── compile_commands.json       # Compilation database (ignore).
└── example_db.json             # This is where the data will be stored.
```

## Documenting

Every header file should contain a brief explanation about what are they used
for. Source files (C++ files) does not include documentation. They may contain
a few comments which explains a little bit about what is going on there.

Each folder inside of `src/` folder should contain the documentation of files
and folders inside of it.

As a contributor, you should also follow this approach. Do not put
documentation in C++ source files. Those may go in the header files. Also, you
should make your code self descriptive
(see [Naming](https://google.github.io/styleguide/cppguide.html#Naming) in
Google's C++ style guide) so that other developers do not have a hard time to
understand your code. But do not over-explain your code.

## Commit messages

Writing good commit messages enhances collaboration, comprehension and ensures
project maintainability. It is always recommended to write clear and concise
commit messages. For git commit messages, we follow
[Conventional Commits](https://www.conventionalcommits.org). This convention
provides a consistent format and structure to your commit messages, making it
easier to understand the purpose and impact of each commit.

Please ensure that your commit messages follow the format:

```
<type>: <description>
```

The `<type>` should be one of the following:

- `feat`: A new feature or enhancement.
- `fix`: A bug fix.
- `docs`: Documentation-related changes.
- `style`: Code style-related changes (e.g., formatting, indentation).
- `refactor`: Code refactoring without changes in functionality.
- `test`: Adding or modifying tests.
- `chore`: Maintenance tasks, build system updates, etc.

The `<description>` should be a brief, descriptive summary of your changes. It
is also recommended to include any relevant issue or pull request numbers in
the commit message. It helps issue trackers to track an issue whether it has
been resolved or not.

Example commit messages:

- `feat: Add user authentication feature`
- `fix: Login validation. Fixes #139`
- `docs: Update README with usage instructions`

Following this convention helps to maintain a clean and meaningful commit
history, making it easier for everyone to understand and navigate the
project's development.

**Additional resources:**

- [How to Write Good Commit Messages: A Practical Git Guide](https://www.freecodecamp.org/news/writing-good-commit-messages-a-practical-guide/)

## Style guidelines

We follow
[Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).
It helps other contributors to understand one's code. We have
[clang-format](https://clang.llvm.org/docs/ClangFormat.html) (A C++ code
formatter) included in the project with a configuration file
([.clang-format](.clang-format)) that follows Google's C++ style guide. If you
use other formatting tool, make sure that it follows Google's style guide.

## Development environment setup

After cloning the repository, navigate to it and run these. This snippet below
will create `build/` and `lib/` which is required for development and will
install a [JSON](https://github.com/nlohman/json) parser library into the
`lib/` folder.

```sh
mkdir build
mkdir lib

# Installing dependencies
git clone https://github.com/nlohman/json lib/nlohmann_json

# To check whether the library is installed or not.
ls lib
```

### Compile and run the program

We use [CMake](https://cmake.org) to generate build files for our program. To
generate build files, navigate to the `build/` folder and run CMake.

```sh
cd build
cmake ..
```

You will see bunch of build files have been generated. For now, it will
generate build files for [GNU Make](https://www.gnu.org/software/make).

Finally, run `make` to compile the program. The compiled binary will be in the
`bin/` folder. To run the binary, run `./bin/authenticate`.

All together:

```sh
cd build

# Do not run cmake unless you change CMakeLists.txt
cmake ..

# Do not run make unless you change files of src directory
make

# To run the program
./bin/authenticate
```
