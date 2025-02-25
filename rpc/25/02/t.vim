set relativenumber
set number
syntax enable
set shiftwidth=4
let mapleader=" "
nmap <Leader>w :w<CR>
set smartindent
set autoindent
set cindent

nnoremap <F9> :!g++ -std=c++17 % -o %:r && ./%:r<CR>
nnoremap <F8> :!g++ -std=c++17 % -o %:r && ./%:r < input > out; cat out<CR>
