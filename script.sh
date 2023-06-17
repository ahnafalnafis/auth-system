run() {
  g++ $1 -o "$1.out"
  ./"$1.out"
}

build() {
  g++ src/*.cpp -o bin/app
}

clean() {
  find . -name \*.out -type f -delete
}
