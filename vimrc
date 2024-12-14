
colorscheme torte
set background=dark

syntax enable			" Enable syntax highlighting
filetype plugin on		" Enable filetype plugins
filetype indent on

" Vim jump to the last position when reopening a file
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

set showcmd				" Show (partial) command in status line.
set showmatch			" Show matching brackets.
set mat=2        		" Time show
set ignorecase			" Do case insensitive matching
set smartcase			" Do smart case matching
set hlsearch			" Hightlight search
set incsearch			" Incremental search
set autowrite			" Auto save before cmds like :next and :make
set hidden				" Hide buffers when they are abandoned
set mouse=a				" Enable mouse usage (all modes)
set nu					" Lines numbers
set foldcolumn=1		 " Add a bit extra margin to the left
set magic				 " For regular expressions turn magic on
set ruler				 " Always show current position
set cmdheight=2			 " Height of the command bar

set noexpandtab			 " Don't use spaces instead of tabs
set shiftwidth=4
set tabstop=4			 " 1 tab == 4 spaces
set tw=80

set ai                  " Auto-indent
set si                  " Smart indent
set wrap                " Wrap lines

set wildmenu						" Turn on the Wild menu
set wildmode=list:full
set path+=**
set wildignore=*.o,*.out,*~,*.pyc	" Ignore compiled files
set wildignorecase
set wildcharm=<C-z>					" list buffers in the wildmenu with an empty prompt

" :W sudo saves the file
command! W execute 'w !sudo tee % > /dev/null' <bar> edit!

" Move between buffers
nnoremap <PageUp>   :bprevious<CR>
nnoremap <PageDown> :bnext<CR>
" gb -> list buffers and prompt you
nnoremap gb :ls<CR>:b<Space>

" Move between windows
map <C-j> <C-W>j
map <C-k> <C-W>k
map <C-h> <C-W>h
map <C-l> <C-W>l

map <C-w>t :terminal<cr>
map <C-w>e :Explore<cr>

" Manage tabs
let mapleader = ","
map ,j  :tabprevious<cr>
map ,k  :tabnext<cr>
map ,n :tabnew<cr>
map ,o :tabonly<cr>
map ,c :tabclose<cr>
map ,e :tabedit<cr>
map ,m :tabmove<cr>

" No annoying sound on errors
"set noerrorbells
"set novisualbell
"set t_vb=
"set tm=500
set noeb vb t_vb=

" Abbreviations
func Eatchar(pat)
  let c = nr2char(getchar(0))
  return (c =~ a:pat) ? '' : c
endfunc

iab <silent> #i #include <unistd.h><CR><C-R>=Eatchar('\s')<CR>
iab <silent> ## #include <><Left><C-R>=Eatchar('\s')<CR>
iab <silent> ii int main(int argc, char **argv)<CR>{<CR>if (argc)<CR>{<CR><CR>}<CR>return (0);<CR>}<up><up><up><Tab><Tab><C-R>=Eatchar('\s')<CR>
iab <silent> im int main()<CR>{<CR><CR>return (0);<CR>}<up><up><Tab><C-R>=Eatchar('\s')<CR>

iab <silent> if if ()<Left><C-R>=Eatchar('\s')<CR>
iab <silent> ei else if ()<Left><C-R>=Eatchar('\s')<CR>
iab <silent> el else<CR><Tab><C-R>=Eatchar('\s')<CR>
iab <silent> wh while ()<Left><C-R>=Eatchar('\s')<CR>
iab { {<CR>}<up>

iab <silent> it int	i;<CR><CR>i = 0;<CR><C-R>=Eatchar('\s')<CR>
iab <silent> ijt int	i;<CR>int	j;<CR><CR>i = 0;<CR>j = 0;<CR><C-R>=Eatchar('\s')<CR>
iab <silent> 00 '\0'<Right><C-R>=Eatchar('\s')<CR>
iab <silent> pf printf("%",);<Left><Left><Left><Left><C-R>=Eatchar('\s')<CR>
iab <silent> re return ();<Left><Left><C-R>=Eatchar('\s')<CR>
iab <silent> ma malloc();<Left><Left><C-R>=Eatchar('\s')<CR>
iab <silent> fr free();<Left><Left><C-R>=Eatchar('\s')<CR>
iab <silent> si sizeof()<Left><C-R>=Eatchar('\s')<CR>
iab <silent> wr write(,,);<Left><Left><Left><Left><C-R>=Eatchar('\s')<CR>

" Ctrl+\ - Open the definition in a new tab
map <C-\> :tab split<CR>:exec("tag ".expand("<cword>"))<CR>

" Source a global configuration file if available
"if filereadable("/etc/vim/vimrc.local")
"  source /etc/vim/vimrc.local
"endif
