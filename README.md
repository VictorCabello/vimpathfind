# vimpathfind

Vim is a great editor, but it can sometimes be difficult to find the file you need to edit, especially in a large codebase.

Vim's `:find` command helps you locate files based on your `path` setting. By default, this only includes the directory where you started Vim.

You can enable recursive searching with `:set path+=**`, but this doesn't allow you to filter by file extension.

I created this small C program to practice my programming skills and to provide a quick way to populate Vim's `path` with only the directories containing files with specific extensions.

Here is an example of how you can start Vim with this program to include all subdirectories containing `.c` or `.h` files in the `path`:

```bash
vim --cmd "set path+=$(vimpathfind c h)"
```

## Build

```sh
./configure
make
```

## Test

```sh
make check

```
## Install 

 ```sh
sudo make install
```
