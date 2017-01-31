#
# define compiler and compiler flag variables
#

JFLAGS = -g
JC = javac

SOURCE = Launcher.java MCFrame.java MultiMCLauncher.java
CLASSES = net MCFrame.class MultiMCLauncher.class

default: jar

all: jar

jar: classes
	jar -cfe ../MultiMC_Launcher.jar MultiMCLauncher $(CLASSES)

classes:
	$(JC) $(JFLAGS) -d . $(SOURCE)	

clean:
	$(RM) *.class ../MultiMC_Launcher.jar
	
distclean: clean