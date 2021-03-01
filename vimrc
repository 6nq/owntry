set nocompatible              " 去除VI一致性,必须要添加
set smartindent "当在大括号中间回车的时候，他会智能缩进，因为他知道括号中间要缩进
set tabstop=4
set shiftwidth=4
set expandtab
syntax on " 自动语法高亮
set number " 显示行号
"设置代码参考线
highlight ColorColumn ctermbg=darkgray
set colorcolumn=140

"EX命令行格式命令历史记录保存条数
set history =50

"按键映射"
    "
    nnoremap & :&&<CR>
    xnoremap & :&&<CR>
    "
    "将{替换为{}ESCi
    "
    "
    set ttimeout ttimeoutlen=25
    "
    "设置跳出自动补全的括号
        function! SkipPair()
            let char = getline('.')[col('.') - 1]
            if  char == ')' || char == ']' || char == '"' || char == "'" || char == '}'|| char == "." || char == ';'
                return "\<ESC>la"  
            else  
                return "\<TAB>"
            endif  
        endfunction 

    "" 将tab键绑定为跳出括号  
    inoremap jk <c-r>=SkipPair()<CR>


    "将<C-Space>替换为 <Esc>
    inoremap <C-Space> <Esc>
    "
    cnoremap <expr> %% getcmdtype() == ':' ? expand('%:h').'/' : '%%'

    set tags=./tags,tags; "ctags配置
    autocmd Filetype c autocmd BufWritePost * call system("ctags -R -o .tags")

""各类配置
    " 高亮显示当前行
    set cursorline 
      "red（红），white（白），black（黑），green（绿），yellow（黄），blue（蓝），purple（紫），gray（灰），brown（棕），tan(褐色)，syan(青色)
    hi CursorLine   cterm=NONE ctermbg=darkgray ctermfg=NONE
    "hi CursorColumn cterm=NONE ctermbg=darkred ctermfg=white 
    set ruler " 打开状态栏标尺
    set shiftwidth=4 " 设定 << 和 >> 命令移动时的宽度为 4
    set softtabstop=4 " 使得按退格键时可以一次删掉 4 个空格
    set tabstop=4 " 设定 tab 长度为 4
    set nobackup " 覆盖文件时不备份
    "set autochdir " 自动切换当前目录为当前文件所在的目录
    set backupcopy=yes " 设置备份时的行为为覆盖
    set ignorecase smartcase " 搜索时忽略大小写，但在有一个或以上大写字母时仍保持对大小写敏感
    "set nowrapscan " 禁止在搜索到文件两端时重新搜索
    set incsearch " 输入搜索内容时就显示搜索结果
    set hlsearch " 搜索时高亮显示被找到的文本
    set noerrorbells " 关闭错误信息响铃
    set novisualbell " 关闭使用可视响铃代替呼叫
    set t_vb= " 置空错误铃声的终端代码
    set showmatch " 插入括号时，短暂地跳转到匹配的对应括号
    " set matchtime=2 " 短暂跳转到匹配括号的时间

    set magic " 设置魔术
    set hidden " 允许在有未保存的修改时切换缓冲区，此时的修改由 vim 负责保存
    set smartindent " 开启新行时使用智能自动缩进 set backspace=indent,eol,start
    " 不设定在插入状态无法用退格键和 Delete 键删除回车符
    set cmdheight=1 " 设定命令行的行数为 1
    set laststatus=2 " 显示状态栏 (默认值为 1, 无法显示状态栏)
    set statusline=\ %<%F[%1*%M%*%n%R%H]%=\ %y\ %0(%{&fileformat}\ %{&encoding}\ %c:%l/%L%)\

    ""折叠
    " 设置在状态行显示的信息
    set nofoldenable " 开启折叠
    set foldmethod=indent " 设置缩进折叠************************
    set foldcolumn=0 " 设置折叠区域的宽度
    setlocal foldlevel=1 " 设置折叠层数为
    "set foldclose=all " 设置为自动关闭折叠
    nnoremap <space> @=((foldclosed(line('.')) < 0) ? 'zc' : 'zo')<CR>
    " 用空格键来开关折叠


filetype off                  " 必须要添加


""插件管理
call plug#begin('~/.vim/plugged')
    Plug 'preservim/nerdtree'
        "o 打开关闭文件或者目录
        "t 在标签页中打开
        "T 在后台标签页中打开
        "! 执行此文件
        "p 到上层目录
        "P 到根目录
        "K 到第一个节点
        "J 到最后一个节点
        "u 打开上层目录
        "m 显示文件系统菜单（添加、删除、移动操作）
        "? 帮助
        "q 关闭

    Plug 'skywind3000/asyncrun.vim'
        " 自动打开 quickfix window ，高度为 6
        let g:asyncrun_open = 6

        " 任务结束时候响铃提醒
        let g:asyncrun_bell = 1

        " 设置 F10 打开/关闭 Quickfix 窗口
        nnoremap <F10> :call asyncrun#quickfix_toggle(6)<cr>
        "F9 为编译单文件:
        " C Compiler:
        autocmd FileType c nnoremap <silent> <F9> :AsyncRun gcc  -Wall  -O2 "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).o" -lapue <cr>        
        " C++ Compiler
        "autocmd FileType cpp nnoremap <silent> <F9> :AsyncRun  g++  -Wall -O2 "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).o" <cr>        
        " C++20 Compiler
        "autocmd FileType cpp nnoremap <silent> <F9> :AsyncRun g++ "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).o" -Ofast -std=c++20 -s -flto <cr>
        autocmd FileType cpp nnoremap <silent> <F9> :AsyncRun g++ "$(VIM_FILEPATH)" -o "$(VIM_FILEDIR)/$(VIM_FILENOEXT).o"  -std=c++20 -s  <cr>
        " Python Interpreter
        autocmd FileType python nnoremap <silent> <F9> :!python % <CR>
        "mzscheme
        autocmd FileType scheme nnoremap <silent> <F9> :!mzscheme -r %<CR>
        " Bash script
        autocmd FileType sh nnoremap <silent> <F9> :!bash % <CR>
        "vimscript
        autocmd FileType vim nnoremap <silent>
        "F5为运行文件
        nnoremap <silent> <F5> :AsyncRun -raw -cwd=$(VIM_FILEDIR) "$(VIM_FILEDIR)/$(VIM_FILENOEXT).o" <cr>
        "F7编译整个项目
        let g:asyncrun_rootmarks = ['.svn', '.git', '.root', '_darcs', 'build.xml'] 
        nnoremap <silent> <F7> :AsyncRun -cwd=<root> make <cr>
        "F8运行当前项目
        nnoremap <silent> <F8> :AsyncRun -cwd=<root> -raw make run <cr>
        "F6执行测试
        nnoremap <silent> <F6> :AsyncRun -cwd=<root> -raw make test <cr>
        "F4更新Makefile文件，如果不用cmake可以忽略
        nnoremap <silent> <F4> :AsyncRun -cwd=<root> cmake . <cr>
        "由于 C/C++ 标准库的实现方式是发现在后台运行时会缓存标准输出直到程序退出，你想实时看到 printf 输出的话需要 fflush(stdout) 一下，或者程序开头关闭缓存：setbuf(stdout, NULL); 即可。
        "同时，如果你开发 C++ 程序使用 std::cout 的话，后面直接加一个 std::endl 就强制刷新缓存了，不需要弄其他。而如果你在 Windows 下使用 GVim 的话，可以弹出新的 cmd.exe 窗口来运行刚才的程序：
        nnoremap <silent> <F5> :AsyncRun -cwd=$(VIM_FILEDIR) -mode=4 "$(VIM_FILEDIR)/$(VIM_FILENOEXT).o" <cr>
        nnoremap <silent> <F8> :AsyncRun -cwd=<root> -mode=4 make run <cr>
        
        "F4：使用 cmake 生成 Makefile
        "F5：单文件：运行
        "F6：项目：测试
        "F7：项目：编译
        "F8：项目：运行
        "F9：单文件：编译
        "F10：打开/关闭底部的 quickfix 窗口


    Plug 'dense-analysis/ale'
        let g:ale_linters_explicit = 1
        let g:ale_completion_delay = 500
        let g:ale_echo_delay = 20
        let g:ale_lint_delay = 500
        let g:ale_echo_msg_format = '[%linter%] %code: %%s'
        let g:ale_lint_on_text_changed = 'normal'
        let g:ale_lint_on_insert_leave = 1
        let g:airline#extensions#ale#enabled = 1

        let g:ale_c_gcc_options = '-Wall -O2 -std=c99'
        let g:ale_cpp_gcc_options = '-Wall -O2 -std=c++14'
        let g:ale_c_cppcheck_options = ''
        let g:ale_cpp_cppcheck_options = ''

        let g:ale_sign_error = "\ue009\ue009"
        "hi! clear SpellBad
        "hi! clear SpellCap
        "hi! clear SpellRare
        "hi! SpellBad gui=undercurl guisp=red
        "hi! SpellCap gui=undercurl guisp=blue
        "hi! SpellRare gui=undercurl guisp=magenta
"
    Plug 'kana/vim-textobj-user'
    Plug 'kana/vim-textobj-indent'
    Plug 'kana/vim-textobj-syntax'
    Plug 'kana/vim-textobj-function', { 'for':['c', 'cpp', 'vim', 'java'] }
    Plug 'sgur/vim-textobj-parameter'
    "它新定义的文本对象主要有：
    "
        "i, 和 a, ：参数对象，写代码一半在修改，现在可以用 di, / ci, 一次性删除/改写当前参数
        "ii 和 ai ：缩进对象，同一个缩进层次的代码，可以用 vii 选中，dii / cii 删除或改写
        "if 和 af ：函数对象，可以用 vif / dif / cif 来选中/删除/改写函数的内容
    "
    "最开始我不太想用额外的文本对象，一直在坚持 Vim 固有的几个默认对象，生怕手练习惯了肌肉形成记忆到远端没有环境的 vim 下形成依赖改不过来，后来我慢慢发现挺有用的，比如改写参数，以前是比较麻烦的事情，这下流畅了很多，当我发现自己编码效率得到比较大的提升时，才发现习惯依赖不重要，行云流水才是真重要。以前看到过无数次都选择性忽略的东西，有时候试试可能会有新的发现。

    Plug 'octol/vim-cpp-enhanced-highlight'
    "高亮辅助

    Plug 'Yggdroot/LeaderF'
    "异步查找 支持 正则表达式 模糊匹配
    "实时过滤
    "需要python前置
        "<C-C>, <ESC> : 退出 LeaderF. 
        "<C-R> : 在模糊匹配和正则式匹配之间切换
        "<C-F> : 在全路径搜索和名字搜索之间切换
        "<Tab> : 在检索模式和选择模式之间切换
        "<C-J>, <C-K> : 在结果列表里选择
        "<C-X> : 在水平窗口打开
        "<C-]> : 在垂直窗口打开
        "<C-T> : 在新标签打开
        "<C-P> : 预览结果

    "自动补全
    Plug 'ycm-core/YouCompleteMe'
        " YouCompleteMe
        " Python Semantic Completion
        let g:ycm_python_binary_path = '/usr/bin/python3'
        " C family Completion Path
        let g:ycm_global_ycm_extra_conf='~/.ycm_extra_conf.py'
        " 跳转快捷键
        nnoremap <c-k> :YcmCompleter GoToDeclaration<CR>|
        nnoremap <c-h> :YcmCompleter GoToDefinition<CR>|
        nnoremap <c-j> :YcmCompleter GoToDefinitionElseDeclaration<CR>|
        " 停止提示是否载入本地ycm_extra_conf文件
        let g:ycm_confirm_extra_conf = 0
        " 语法关键字补全
        let g:ycm_seed_identifiers_with_syntax = 1
        " 开启 YCM 基于标签引擎
        let g:ycm_collect_identifiers_from_tags_files = 1
        " 从第2个键入字符就开始罗列匹配项
        let g:ycm_min_num_of_chars_for_completion=2
        " 在注释输入中也能补全
        let g:ycm_complete_in_comments = 1
        " 在字符串输入中也能补全
        let g:ycm_complete_in_strings = 1
        " 注释和字符串中的文字也会被收入补全
        let g:ycm_collect_identifiers_from_comments_and_strings = 1
        " 弹出列表时选择第1项的快捷键(默认为<TAB>和<Down>)
        let g:ycm_key_list_select_completion = ['<C-n>', '<Down>']
        " 弹出列表时选择前1项的快捷键(默认为<S-TAB>和<UP>)
        let g:ycm_key_list_previous_completion = ['<C-p>', '<Up>']
        " 主动补全, 默认为<C-Space>
        "let g:ycm_key_invoke_completion = ['<C-y>']
        " 停止显示补全列表(防止列表影响视野), 可以按<C-Space>重新弹出
        "let g:ycm_key_list_stop_completion = ['<C-y>']


        let g:ycm_semantic_triggers =  {
        \   'c,cpp,python,java,go,erlang,perl,scheme':['re!\w{2}'],
        \   'cs,lua,javascript':['re!\w{2}'],
        \}
        "ycm默认需要按ctrl + space 来进行补全，可以在上面的花括号里面加入下面两行代码来直接进行补全[不需要按键]



        let g:ycm_add_preview_to_completeopt = 0
        "关闭函数原型提示
        
    "安装插件

    Plug 'vim-airline/vim-airline'
        ""Vim 在与屏幕/键盘交互时使用的编码(取决于实际的终端的设定)        
        set encoding=utf-8
        set langmenu=zh_CN.UTF-8
        ""设置打开文件的编码格式  
        set fileencodings=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1 
        set fileencoding=utf-8
        ""解决菜单乱码
        source $VIMRUNTIME/delmenu.vim
        source $VIMRUNTIME/menu.vim
        ""解决consle输出乱码
        "set termencoding = cp936  
        ""设置中文提示
        language messages zh_CN.utf-8 
        ""设置中文帮助
        set helplang=cn
        ""设置为双字宽显示，否则无法完整显示如:
        set ambiwidth=double
        ""总是显示状态栏 
        let laststatus = 2
        let g:airline_powerline_fonts = 1   " 使用powerline打过补丁的字体
        let g:airline_theme="dark"      " 设置主题
        ""开启tabline
        let g:airline#extensions#tabline#enabled = 1      "tabline中当前buffer两端的分隔字符
        let g:airline#extensions#tabline#left_sep = ' '   "tabline中未激活buffer两端的分隔字符
        let g:airline#extensions#tabline#left_alt_sep = '|'      "tabline中buffer显示编号
        let g:airline#extensions#tabline#buffer_nr_show = 1      
        ""映射切换buffer的键位
        nnoremap [b :bp<CR>
        nnoremap ]b :bn<CR>
        ""设置字体 
        set guifont=Powerline_Consolas:h14:cANSI

    ""超级substitute
    Plug 'tpope/vim-abolish'

    "代码查询"
    Plug 'SirVer/ultisnips'
        let g:UltiSnipsExpandTrigger="<tab>"
        " 使用 tab 切换下一个触发点，shit+tab 上一个触发点
        let g:UltiSnipsJumpForwardTrigger="<tab>"
        let g:UltiSnipsJumpBackwardTrigger="<C-tab>"
        " 使用 UltiSnipsEdit 命令时垂直分割屏幕
        let g:UltiSnipsEditSplit="vertical"        
    " Optional:代码片段补全
    Plug 'honza/vim-snippets'

    Plug 'tpope/vim-fugitive'
    " -u NONE -c "helptags fugitive/doc" -c q

    Plug 'tpope/vim-commentary'
    autocmd Filetype c setlocal commentstring=//\%s
        "gcc     注释当前行（普通模式）
        "gc      可视模式下，注释当前选中的部分
        "gcu     撤销上一次注释的部分，可以是一行也可以是多行
        "gcgc    撤销注释当前行和邻近的上下两行
    Plug 'jiangmiao/auto-pairs'

        let g:AutoPairs = {'(':')', '[':']', '{':'}',"'":"'",'"':'"'}
            "设置要自动配对的符号
        "let g:AutoPairs['<']='>'
            "添加要自动配对的符号<>
        "let b:AutoPairs = g:AutoParis
            ""设置要自动配对的符号，默认为g:AutoPairs，可以通过自动命令来对不同文件类型设置不同自动匹配对符号。
        let g:AutoPairsShortcutToggle = '<M-p>'
            ""设置插件打开/关闭的快捷键，默认为ALT+p。
        let g:AutoPairsShortcutFastWrap = '<M-e>'
            ""设置自动为文本添加圆括号的快捷键，默认为ALT+e。
        let g:AutoPairsShortcutJump = '<M-n>'
            ""设置调到下一层括号对的快捷键，默认为ALT+n。
        let g:AutoPairsShortcutBackInsert = '<M-b>'
            ""设置撤销飞行模式的快捷键，默认为ALT+b。
        let g:AutoPairsMapBS = 1
            ""把BACKSPACE键映射为删除括号对和引号，默认为1。
        let g:AutoPairsMapCh = 1
            ""把ctrl+h键映射为删除括号对和引号，默认为1。
        let g:AutoPairsMapCR = 1
            ""把ENTER键映射为换行并缩进，默认为1。
        let g:AutoPairsCenterLine = 1
            ""当g:AutoPairsMapCR为1时，且文本位于窗口底部时，自动移到窗口中间。
        let g:AutoPairsMapSpace = 1
           "" 把SPACE键映射为在括号两侧添加空格，默认为1。
        let g:AutoPairsFlyMode = 0
            "启用飞行模式，默认为0。
        let g:AutoPairsMultilineClose = 1
        "启用跳出多行括号对，默认为1，为0则只能跳出同一行的括号。
        
        " 
        "成对插入	{}，[]，()，”“，”，“		[	[|]
        "成对删除	{}，[]，()，”“，”，“	foo[|]	BACKSPACE	foo|
        "换行并自动缩进	{}，[]，()	node{|}	ENTER	node{
        "  |
        "}
        "在括号内两侧各插入空格	{}，[]，()	foo{|}	SPACE	foo{ | }
        "词后单引号不成对插入	‘	foo|	‘	foo’|
        "跳过右括号	{}，[]，()	[ foo| ]	]	[ foo ]|
        "在转义符\后禁用插件	{}，[]，()，”“，”，“	foo\|	{	foo\{|
        "对字符串加小括号	C风格字符串	|’foo’	ALT+e	(‘foo’)|
        "删除重复成对符号	{}，[]，()，”，”“，“	foo”’|”’	BACKSPACE	foo|
        "飞行模式，跳出括号对而不插入	{}，[]，()	if(a[3|])	)	if(a[3])|
        "撤销飞行模式，插入而不是跳出括号对	{}，[]，()	if(a[3])|	ALT+b	if(a[3])|'
    Plug 'ton/vim-alternate'
       nmap <silent> <F1> :Alternate<CR>
       let g:AlternateExtensionMappings =  [{'.cpp' : '.h', '.h' : '.hpp', '.hpp' : '.cpp'}, {'.c': '.h', '.h': '.c'}]
        "   Vim-alternate提供了一个命令来打开该文件的备用文件 加载到当前缓冲区中：
        "   :Alternate
        "   没有提供默认的键盘映射，但用户可以轻松定义。 为了 例如，要将F4映射到：Alternate，请将以下行添加到Vim中 配置：
        "   nmap <silent> <F4> :Alternate<CR>
        "   然后，Vim-alternate将根据当前文件搜索备用文件。 配置。
        "   有关更多详细信息和示例，请参见“选项”部分。
        "   选项
        "   要设置一个选项，在Vim配置中包括如下一行：
        "   let g:AlternatePaths = ['../itf', '../src', '.', '..']
        "   本节的其余部分列出了所有可用的选项：
        "   g：AlternatePaths
        "   逗号分隔的相对于当前文件的搜索路径列表 用于备用文件。
        "   默认值：
        "   ['.', '../itf', '../include', '../src']
        "   g：AlternateExtensionMappings
        "   将扩展名映射到备用扩展名的词典列表。
        "   默认值：
        "   [{'.cpp' : '.h', '.h' : '.hpp', '.hpp' : '.cpp'}, {'.c': '.h', '.h': '.c'}]

    Plug 'tpope/vim-surround'
        "   
        "   Surround.vim与“周围环境”有关：括号，方括号，引号， XML标签等。 该插件提供了可以轻松删除的映射， 成对更改并添加此类环境。
        "   用示例最容易解释。 按 cs"'内
        "   "Hello world!"
        "   更改为
        "   'Hello world!'
        "   现在按 cs'<q>将其更改为
        "   <q>Hello world!</q>
        "   走了一圈，按 cst"获得
        "   "Hello world!"
        "   要完全删除定界符，请按 ds"。
        "   Hello world!
        "   现在将光标放在“ Hello”上，按 ysiw]（ iw是一个文本对象）。
        "   [Hello] world!
        "   让我们大括号，并添加一些空间（使用 }，而不是 {为没有 空间）： cs]{
        "   { Hello } world!
        "   现在，用 将整个行用括号括起来 yssb或 yss)。
        "   ({ Hello } world!)
        "   恢复为原始文本： ds{ds)
        "   Hello world!
        "   强调你好： ysiw<em>
        "   <em>Hello</em> world!
        "   最后，让我们尝试视觉模式。 按大写字母V（对于逐行 视觉模式），然后按 S<p class="important">。
        "   <p class="important">
          " <em>Hello</em> world!
        "   </p>
        "   这个插件对于HTML和XML编辑非常强大，这是一个利基 目前在Vim土地上似乎未满。 （与HTML / XML相对 inserting ，有许多可用的插件）。 添加，更改， 同时删除成对的标签很容易。
        "   该 .命令将工作 ds， cs以及 yss如果你安装 repeat.vim'

    Plug 'iamcco/markdown-preview.nvim' ,{ 'do': 'cd app && yarn install'  }
        "Need nodejs and yarn
        " set to 1, nvim will open the preview window after entering the markdown buffer
        " default: 0
        let g:mkdp_auto_start = 0

        " set to 1, the nvim will auto close current preview window when change
        " from markdown buffer to another buffer
        " default: 1
        let g:mkdp_auto_close = 1

        " set to 1, the vim will refresh markdown when save the buffer or
        " leave from insert mode, default 0 is auto refresh markdown as you edit or
        " move the cursor
        " default: 0
        let g:mkdp_refresh_slow = 0

        " set to 1, the MarkdownPreview command can be use for all files,
        " by default it can be use in markdown file
        " default: 0
        let g:mkdp_command_for_global = 0

        " set to 1, preview server available to others in your network
        " by default, the server listens on localhost (127.0.0.1)
        " default: 0
        let g:mkdp_open_to_the_world = 0

        " use custom IP to open preview page
        " useful when you work in remote vim and preview on local browser
        " more detail see: https://github.com/iamcco/markdown-preview.nvim/pull/9
        " default empty
        let g:mkdp_open_ip = ''

        " specify browser to open preview page
        " default: ''
        let g:mkdp_browser = ''

        " set to 1, echo preview page url in command line when open preview page
        " default is 0
        let g:mkdp_echo_preview_url = 0

        " a custom vim function name to open preview page
        " this function will receive url as param
        " default is empty
        let g:mkdp_browserfunc = ''

        " options for markdown render
        " mkit: markdown-it options for render
        " katex: katex options for math
        " uml: markdown-it-plantuml options
        " maid: mermaid options
        " disable_sync_scroll: if disable sync scroll, default 0
        " sync_scroll_type: 'middle', 'top' or 'relative', default value is 'middle'
        "   middle: mean the cursor position alway show at the middle of the preview page
        "   top: mean the vim top viewport alway show at the top of the preview page
        "   relative: mean the cursor position alway show at the relative positon of the preview page
        " hide_yaml_meta: if hide yaml metadata, default is 1
        " sequence_diagrams: js-sequence-diagrams options
        " content_editable: if enable content editable for preview page, default: v:false
        " disable_filename: if disable filename header for preview page, default: 0
        let g:mkdp_preview_options = {
            \ 'mkit': {},
            \ 'katex': {},
            \ 'uml': {},
            \ 'maid': {},
            \ 'disable_sync_scroll': 0,
            \ 'sync_scroll_type': 'middle',
            \ 'hide_yaml_meta': 1,
            \ 'sequence_diagrams': {},
            \ 'flowchart_diagrams': {},
            \ 'content_editable': v:false,
            \ 'disable_filename': 0
            \ }

        " use a custom markdown style must be absolute path
        " like '/Users/username/markdown.css' or expand('~/markdown.css')
        let g:mkdp_markdown_css = ''

        " use a custom highlight style must absolute path
        " like '/Users/username/highlight.css' or expand('~/highlight.css')
        let g:mkdp_highlight_css = ''

        " use a custom port to start server or random for empty
        let g:mkdp_port = ''

        " preview page title
        " ${name} will be replace with the file name
        let g:mkdp_page_title = '「${name}」'

        " recognized filetypes
        " these filetypes will have MarkdownPreview... commands
        let g:mkdp_filetypes = ['markdown']        
call plug#end()
