alias paco=%s/francinette/tester.sh

alias f=%s/francinette/tester.sh
alias v='valgrind --leak-check=full --track-fds=all --track-origins=yes'
alias c='gcc -g -Wall -Werror -Wextra'
alias g='gdb -tui'
alias ga='gdb -tui --args'

alias H='cd ~'
alias svim='sudo vim'
alias brc='vim ~/.bashrc'
alias vrc='vim ~/.vimrc'
alias nxc='svim /etc/nixos/configuration.nix'
alias vpn='expressvpn status'
alias vpnc='expressvpn connect'
alias vpnd='expressvpn disconnect'

# Expand the history size
export HISTFILESIZE=10000
export HISTSIZE=500
export HISTTIMEFORMAT="%F %T" # add timestamp to history

# Don't put duplicate lines in the history and do not add lines that start with a space
export HISTCONTROL=erasedups:ignoredups:ignorespace

# Causes bash to append to history instead of overwriting it so if you start a new terminal, you have old session history
shopt -s histappend
PROMPT_COMMAND='history -a'

# Allow ctrl-S for history navigation (with ctrl-R)
[[ $- == *i* ]] && stty -ixon

# Search command line history
alias h="history | grep "

# Ignore case on auto-completion
# Note: bind used instead of sticking these in .inputrc
if [[ $iatest -gt 0 ]]; then bind "set completion-ignore-case on"; fi

# Show auto-completion list automatically, without double tab
if [[ $iatest -gt 0 ]]; then bind "set show-all-if-ambiguous On"; fi


# To have colors for ls
#export CLICOLOR=1
#export LS_COLORS='no=00:fi=00:di=00;34:ln=01;36:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.gz=01;31:*.bz2=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.avi=01;35:*.fli=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.ogg=01;35:*.mp3=01;35:*.wav=01;35:*.xml=00;31:'

alias ls='eza'
alias lr='eza -Rla'
alias la='eza -lah'   
alias lt='eza -Ta'
alias cp='cp -i'
alias mv='mv -i'
alias cd..='cd ..'
alias ..='cd ..'

alias 000='chmod -R 000'
alias 644='chmod -R 644'
alias 666='chmod -R 666'
alias 755='chmod -R 755'
alias 777='chmod -R 777'
alias 700='chmod -R 700'

alias ctar='tar -cvf'
alias utar='tar -xvf'

alias docker-clean=' \
  docker container prune -f ; \
  docker image prune -f ; \
  docker network prune -f ; \
  docker volume prune -f '


# Searches for text in all files in the current folder
ftext() {
	# -i case-insensitive
	# -I ignore binary files
	# -H causes filename to be printed
	# -r recursive search
	# -n causes line number to be printed
	grep -iIHrn --color=always "$1" . | less -r
}

eval "$(starship init bash)"
fastfetch
echo "Hello !"
