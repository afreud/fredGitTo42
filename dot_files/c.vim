" highlight cComment ctermfg=Green guifg=Green
" syntax keyword   Type   int long char contained
highlight cMulti term=bold cterm=bold gui=bold ctermfg=102 guifg=#7f7f7f
highlight Changed term=bold cterm=bold gui=bold  ctermfg=12 guifg=DodgerBlue



syntax match Macro "free" 
syntax match Macro "malloc" 

syntax match Title "&" 
syntax match Title "*" 
syntax match MoreMsg "->"

syntax match Removed ";$"
syntax match MoreMsg "," 
syntax match Constant "\'\\0\'" 
syntax match WarningMsg "\[" 
syntax match WarningMsg "\]" 
syntax match Error "[0-9a-zA-Z_+-]\+$"
syntax match Type "	t_[a-z]\+"
syntax match cMulti "[A-Z_]\+"

syntax match TabLineSel "argc" 
syntax match TabLineSel "argv" 
syntax match TabLineSel "ft_[a-z_]*"
syntax match TabLineSel "("
syntax match TabLineSel ")"

syntax match MoreMsg "|| " 
syntax match MoreMsg "&& " 
syntax match MoreMsg "+ "
syntax match MoreMsg "- "
syntax match MoreMsg "* " 
syntax match MoreMsg "/ " 
syntax match MoreMsg "% " 

syntax match SignColumn "="
syntax match SignColumn "/="
syntax match SignColumn "*="
syntax match SignColumn "+="
syntax match SignColumn "-="
syntax match SignColumn "--"
syntax match SignColumn "++"

syntax match Changed "!"
syntax match Changed ">"
syntax match Changed "<"
syntax match Changed "=="
syntax match Changed ">="
syntax match Changed "<="
syntax match Changed "!="

