nnoremap <F8> :botright terminal ./.vim/z % c<CR>
nnoremap <F9> :botright terminal ./.vim/z %<CR>
nnoremap <F20> :botright terminal ./.vim/z % c i<CR>
nnoremap <F21> :botright terminal ./.vim/z % r i<CR>

augroup cpp_template
autocmd!
autocmd BufNewFile *.cpp 0r ./.vim/template.cpp | execute "normal! }}"
augroup END
