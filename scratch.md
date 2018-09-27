## ksh

You must use your OpenBSD virtual machine for this part of the exercise, so boot it up and log into the `csp` user. I\'ll refer to the \"prompt\"
throughout this lesson and throughout the course. The ksh prompt ends
in the \$ symbol and indicates that you can type commands. Sometimes I
will ask you to clear your terminal by typing `clear` and pressing
Enter. This will erase the content of the command line, but it will not
undo previous commands.

In the virtual machine, type `su -l` and press <span class="keyboardShortcut">Enter</span>. Then type in the password for the root account that I gave you. `su -l` changes you to the root user and allows you to execute commands that affect all users, and can also damage the system. Use this wisely!

Type `pkg_add -u` and wait for it to finish.

Type `pkg_add nano vim git curl` to install those four programs.

Type `exit` to drop back to your `csp` user's shell.

### Checkpoint 14: pwd

This command is an abbreviation for \"print working directory. This
command shows you what directory (folder) you\'re in, which can be
helpful if you are lost. Before you do anything else, just type `pwd` at
the prompt and press <span class="keyboardShortcut">Enter</span>. Do this three times.\

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 15: cd

This command is an abbreviation for \"change directory.\" It allows you
to move from one directory (folder) to another in the command line. It
can also reset your working directory to your home directory, which can
be much faster than changing directories one level at a time.

Type `cd` and press <span class="keyboardShortcut">Enter</span>. Notice that nothing changed. This is because
you just told the computer to change to the current directory.

Type `cd Downloads` and press <span class="keyboardShortcut">Enter</span>. Check to see if your prompt now
includes the Downloads folder just before the \$ symbol. Now, any
commands you execute will run in this directory (folder) instead of your
home directory.

Type `cd ..` and press <span class="keyboardShortcut">Enter</span>. Check to see what your current working
directory is. It should be your home directory. If you\'re not sure,
just type `pwd` and press <span class="keyboardShortcut">Enter</span> to check. If you went down another
directory, you could type `cd ../..` to go back up twice with
one command. We will practice this in the next checkpoint.

Type `cd Mu` and press <span class="keyboardShortcut">Tab</span>. ksh should fill in the missing letters and
show `cd Music/` instead. Now press <span class="keyboardShortcut">Enter</span>. When you\'re using the
command line, you can press <span class="keyboardShortcut">Tab</span> to autocomplete the command, directory,
or file that you are working on instead of typing the whole command.

Next, type `cd ~` and notice that you\'re back in your home directory.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 16: mkdir

This command creates a new directory inside your working directory. You
should be in your home directory. If not, type `cd           ~` and
press <span class="keyboardShortcut">Enter</span> to go there. Then type `mkdir         test` and press <span class="keyboardShortcut">Enter</span>
to create a directory called \"test\" inside your home directory. Then
type `cd test` and press <span class="keyboardShortcut">Enter</span> to go down into the directory you just
created.

Type `mkdir anotherTest` and press <span class="keyboardShortcut">Enter</span> to create another directory
inside the \"test\" directory. Then type `cd         anotherTest` and
press <span class="keyboardShortcut">Enter</span> to go down into this new directory.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 17: ls

This command lists the files and directories inside the current working
directory. Type `cd ~` and press <span class="keyboardShortcut">Enter</span> to go back to your home
directory. Then type `ls` and press <span class="keyboardShortcut">Enter</span> to see what\'s inside the
directory.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 18: rmdir

This command removes directories. Type `cd ~` and press <span class="keyboardShortcut">Enter</span> to return
to your home directory. Then navigate down to the \"test\" directory.
Type `rmdir anotherTest` and press <span class="keyboardShortcut">Enter</span> to delete the \"anotherTest\"
directory and then use `ls` to make sure it has been deleted. Go back to
your home directory and delete the \"test\" directory. Use `ls` to make
sure you have removed it. When you check your home directory in the file
browser you should see that both directories are gone.

Now, type `mkdir -p test/anotherTest` and press <span class="keyboardShortcut">Enter</span>. The `-p` is what
we call a flag and it allows us to modify commands to do something
slightly different. In this case, the `-p` flag allows us to create two
directories, one inside the other, at the same time. Now type
`rmdir            test` and see what happens.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 19: pushd, popd

These two commands allow you to quickly switch between different
directories. It works a little differently in ksh than in PowerShell.

First, type `mkdir -p test/anotherTest/yetAnotherTest` and press <span class="keyboardShortcut">Enter</span>.
Then type `pushd         test/anotherTest/yetAnotherTest` and see what
happens. Confirm that you\'re in the \"yetAnotherTest\" directory with
`pwd`.

Then type `popd` and press <span class="keyboardShortcut">Enter</span>. Now where are you? Confirm this with
`pwd`.

Use `ls` and `pushd` to move to another directory and then use `popd` to
move back. Try this at least three more times using different
directories.

Now, type `cd ~` and press <span class="keyboardShortcut">Enter</span>. Then type
`pushd            test/anotherTest/yetAnotherTest` and press <span class="keyboardShortcut">Enter</span>.
Navigate to any other directory besides \"test\" and then type `pushd`
and press <span class="keyboardShortcut">Enter</span>.

When you run a command all by itself, you\'re running it without any
arguments. What happened when you ran `pushd` without any arguments?

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 20: touch

This command allows you to create new files. First, use `cd` to move to
the \"yetAnotherTest\" directory. Once you get there, type
`touch test.txt` and press <span class="keyboardShortcut">Enter</span>. Confirm you created a new file with
`ls`.

Then go back to your home directory using `cd` and type
`touch test/anotherTest/yetAnotherTest/hello.txt` and press <span class="keyboardShortcut">Enter</span>. Then
confirm you created a new file by typing
`ls            test/anotherTest/yetAnotherTest/` and pressing Enter. You
just created a file in a directory below your current working directory
without actually moving there. Then you listed the contents of that
directory without moving.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 21: cp

This command allows you to copy files and directories from one place to
another as well as within the same directory. Files can be copied
exactly or renamed when copied.

Move to the \"yetAnotherTest\" directory. Type
`cp hello.txt         howdy.txt` and press <span class="keyboardShortcut">Enter</span>. Then use `ls` to see
if you now have three files - test.txt, hello.txt, and howdy.txt - in
the directory. You just copied the file and renamed it at the same time.

Type `mkdir pleaseStop` and press <span class="keyboardShortcut">Enter</span>. Then type
`cp            hello.txt pleaseStop/` and press <span class="keyboardShortcut">Enter</span>. Now when you use
`ls` you should see a new directory inside \"yetAnotherTest\".

Type `cp -r pleaseStop really` and press <span class="keyboardShortcut">Enter</span>. Then use `ls` to make
sure that you can see the \"really\" directory. You just copied a
directory and its contents to a new directory. The `-r` flag stands for
\"recurse\" which affects the directory and all of its contents.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 22: mv

This command is similar to `cp` except that instead of copying the file,
it moves the file to a new location. However, just like `cp`, `mv` can
also rename files at the same time. In fact, most of the time you will
use this command to rename files, not actually move them to a new place.

Make sure you are in the \"yetAnotherTest\" directory and type
`mv            test.txt whenWillThisEnd.txt` and press <span class="keyboardShortcut">Enter</span>. Then use
`ls` to confirm that test.txt is now called whenWillThisEnd.txt instead.

Now type `mv really yesReally` and press <span class="keyboardShortcut">Enter</span>. You can use `ls` to make
sure you\'ve renamed the directory correctly.

Now use `mv` to rename whenWillThisEnd.txt and \"yesReally\" back to
their original names.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 23: less

This command is used to display the contents of a text file, especially
files that are too long to fit into your terminal window.

Use cd to move to the \"yetAnotherTest\" directory. Then type
`curl           -O` and the [URL (link) of the loremIpsum.txt
file](loremIpsum.txt) to download the file to the working directory.

Then type `less loremIpsum.txt` and notice that the whole file is too
large to display in your terminal window. Use the space bar to display
the next section until you have seen the whole file. This is called
paging.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 24: cat

Unlike the last command, this one streams the file to your terminal
without any paging. But you can also stream multiple files to your
terminal. First, press the Home button and open \"yetAnotherTest\" in
the Browse Files application and add some text to each text file besides
loremIpsum.txt using your text editor. Save each file and then move on.

Type `cat loremIpsum.txt` and press <span class="keyboardShortcut">Enter</span>.

Type `cat loremIpsum.txt hello.txt test.txt` and press <span class="keyboardShortcut">Enter</span>. Then try
the command with the text files in a different order.

Can you stream the same file more than once in the same command? What
happens if the output is too long for your terminal window?

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 25: rm

Now we\'re going to clean up our files and directories from this lesson
using the `rm` and `rmdir` commands.

Make sure you\'re in the \"yetAnotherTest\" directory. Then type
`rm            loremIpsum.txt` and press <span class="keyboardShortcut">Enter</span>. Use `ls` to see if the
file is gone. Then use rm to delete all the other files in the
directory.

Now try to use `rmdir` to delete the \"pleaseStop\" and \"really\"
directories. Does it work? In ksh you will get an error, but in
PowerShell you are able to decide what to do with directories that
aren\'t empty.

Now use `cd` to go to your home directory. Then type `rm -rf test` in
order to delete the whole directory, including its contents. The `-f`
flag means \"force\" which deletes the directory even if there are
things inside it.

Both commands can delete directories and files, but which one do you use
to delete files in the working directory? You should always use `rm` and
`rmdir` very carefully since it\'s easy to damage your system by
accidentally deleting files.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

### Checkpoint 26: exit

This command allows you to close the terminal. Type `exit` and press
Enter to close the terminal. You can then power down your virtual machine.

<p class="checkpoint">Raise your hand and have Mr. Olinda verify this checkpoint.</p>

## Study Tips

-   Understand what the PowerShell or ksh commands *do* when you use
    them.
-   Understand that the same task can sometimes be accomplished with
    different commands.\
-   Understand the difference between commands (example: cp), flags
    (example: -r), and arguments (example: foo.md).
-   Practice constructing valid command prompt statements using
    different commands, flags, and arguments.
-   Practice labeling the different parts of command prompt statements.\
