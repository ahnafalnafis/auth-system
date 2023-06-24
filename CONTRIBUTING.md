# Welcome to Login and Registration system contributing guide

Thank you for investing your time in contributing this project!

## Getting started

If you are a new contributor, I hope that you read the [README](README.md) you
will get the overview of the project.

Project structure:

`*` marked files or folders should not be included in the git repository. They
should exists in the project folder when it is being developed.

```
[PROJECT DIRECTORY]
├── bin                 - This is where your binaries(*) will go to.
│   └── app
├── build.sh            - To automate the build process.
├── .clang-format       - Code formatting settings.
├── CONTRIBUTING.md
├── database.json       - This is where the data(*) will be stored.
├── .gitignore
├── LICENSE
├── README.md
└── src
    ├── database.cpp    - Database handler.
    ├── database.h
    ├── main.cpp
    ├── user.cpp        - User handler.
    ├── user.h
    ├── utils.cpp       - Utility functions.
    └── utils.h
```

## Documenting

Each header files contains brief explanation about what they are doing or why
they are made. Source files (C++ files) does not include documentation or
explanation. They may contain few comments which explains a little bit about
what is going on there.

A contributor should follow this approach. One should not put documentation in
C++ source files. Those may go in the header files. And also, one should make
their code self descriptive so that other developers do not have to look up
into the header files. But no one should make their code over descriptive.

## Style guides

We are trying to follow [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).
Make sure that you follow the same style guide. It helps other developers to
understand one's code. We have included a [.clang-format](.clang-format) into
our repository, so that one can use it format their code with
[clang-format](https://clang.llvm.org/docs/ClangFormat.html) (A C++ code
formatter). If you use other formatter then make sure that that formatter is
using Google's style guide.
