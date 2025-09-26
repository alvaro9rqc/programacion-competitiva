nnoremap <F8> :botright terminal ./.vim/z % c<CR>
nnoremap <F9> :botright terminal ./.vim/z %<CR>
 
augroup cpp_template
  autocmd!
  autocmd BufNewFile *.cpp 0r ./.vim/template.cpp | normal Gkk
augroup END
