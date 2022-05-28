:au BufNewFile *.cpp r ~/.vim/templates/basic.cpp
:au BufNewFile *.java r ~/.vim/templates/basic.java

:set guifont=*<F2>

:set noundofile

:set autowrite

:set autoread

:inoremap <c-z> <c-o>:u<CR>

:filetype plugin indent on

:set number

":highlight LineNr term=bold cterm=NONE ctermfg=DarkGrey ctermbg=NONE gui=NONE guifg=DarkGrey guibg=NONE

:set cpoptions+=n

:set nocompatible

:set exrc

:set mouse=a

:syntax on

:set showmode

:set showcmd

:set encoding=utf-8

:set t_Co=256

:set autoindent

:set smartindent

:set cindent

:set tabstop=4

:set shiftwidth=4

:set expandtab

:set softtabstop=4

:set textwidth=80

:set wrap

:set nowrap

:set noswapfile

:set linebreak

:set wrapmargin=2

:set scrolloff=8

:set sidescrolloff=8

:set laststatus=2

:set ruler

:set showmatch

:set hlsearch

:set incsearch

:set smartcase

:set smarttab

:set backspace=indent,eol,start

set rulerformat=%55(%{strftime('%a\ %b\ %e\ %I:%M\ %p')}\ %5l,%-6(%c%V%)\ %P%)

:set clipboard=unnamed

noremap <C-m> :normal! I//<CR>

"autocmd filetype cpp nnoremap <F2> :w <bar> !clear && timeout 10s g++ -std=gnu++14 -O2 % -o %:p:h/%:t:r && timeout 100s ./%:r<CR>
autocmd filetype cpp nnoremap <C-t> :w<CR> :! g++ %:r.cpp -o run && ./run <CR>
autocmd filetype cpp nnoremap <C-d> :w<CR> :! clear && g++ -g -std=c++17 -Wall -Wextra -Wno-unused-result -D PC -O2 %:r.cpp -o %:r && printf "============ Made By: Piyush Mittal ==============\n\n\n"  && cp %:r.cpp /home/mittalpiyush/submit.cpp && ./%:r <CR>
autocmd filetype cpp nnoremap <C-c> :w<CR> :!printf "\033c" && g++ -g -std=c++17 -D ONLINE_JUDGE -O2 %:r.cpp -o run && ./run < input.in <CR>
autocmd filetype c nnoremap <C-c> :w <bar> !gcc -std=c99 -lm % -o %:p:h/%:t:r.out && ./%:r.out<CR>
autocmd filetype java nnoremap <C-c> :w <bar> !printf "\033c" && javac % && java -enableassertions %:r <CR>
autocmd filetype python nnoremap <C-c> :w <bar> !python % <CR>
autocmd filetype perl nnoremap <C-c> :w <bar> !perl % <CR>
autocmd filetype go nnoremap <C-c> :w <bar> !go build % && ./%:p <CR>

nnoremap <C-l> ggdG
" nnoremap 

function! LogSignature() abort
    let firstname = "Created By: 'Present_Sir'"
    let prefix1 = "/*"
    let prefix2 = "*/"

    let comment_start = prefix1
    let signature_undated = "\t" . "*" . "\t" . firstname
    let signature = "\t" . "*" . "\t" . "Created On: " . strftime('%c')
    let comment_end = prefix2

    "Insert signature
     call append('.', [comment_start , signature_undated , signature , comment_end])

endfunction

command Powerr :r ~/.vim/Shortcut/BinaryExpo.h
command BLifting :r ~/.vim/Shortcut/BinaryLifting.h
command Debug :r ~/.vim/Shortcut/Debug.h
command Dsu :r ~/.vim/Shortcut/DisjointSetUnion.h
command Factors :r ~/.vim/Shortcut/Factors.h
command Hld :r ~/.vim/Shortcut/HeavyLightDecomposition.h
command Lsegtree :r ~/.vim/Shortcut/Lazy_Segtree.h
command Mint :r ~/.vim/Shortcut/Mint.h
command Segtree :r ~/.vim/Shortcut/Segtree.h
command Sieve :r ~/.vim/Shortcut/Sieve.h

nnoremap <F5> :call LogSignature()<cr>
