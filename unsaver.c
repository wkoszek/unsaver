/*2:*/
#line 15 "unsaver.w"

#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <unistd.h>  

/*:2*//*3:*/
#line 25 "unsaver.w"

#include <X11/Xlib.h> 
#include <X11/Xutil.h> 
#include <X11/Xresource.h> 

/*:3*//*4:*/
#line 37 "unsaver.w"

static int g_got_sig= 0;

static void
got_sig(int sig_num)
{

g_got_sig= sig_num;
}

/*:4*//*5:*/
#line 49 "unsaver.w"


int
main(int argc,char**argv)
{
/*6:*/
#line 71 "unsaver.w"

int o;
Display*dpy;
Window root_window;
int move,move_const,sleep_amt;


/*:6*/
#line 54 "unsaver.w"
;
/*7:*/
#line 82 "unsaver.w"

signal(SIGINT,got_sig);
setbuf(stdout,NULL);
setbuf(stderr,NULL);

/*:7*/
#line 55 "unsaver.w"
;
/*8:*/
#line 94 "unsaver.w"

move_const= 1;
sleep_amt= 5;
while((o= getopt(argc,argv,"c:s:"))!=-1){
switch(o){
case'c':
move_const= atoi(optarg);
break;
case's':
sleep_amt= atoi(optarg);
break;
default:
fprintf(stderr,"unknown option '%c'\n",
move_const);
exit(1);
}
}
argc-= optind;
argv+= optind;

/*:8*/
#line 56 "unsaver.w"
;
/*9:*/
#line 120 "unsaver.w"


if(sleep_amt<=0){
printf("sleep_amt=%d, must be >= 1. Fixing to 1\n",sleep_amt);
sleep_amt= 1;
}


/*:9*/
#line 57 "unsaver.w"
;
/*10:*/
#line 130 "unsaver.w"

dpy= XOpenDisplay(0);
root_window= XRootWindow(dpy,0);
XSelectInput(dpy,root_window,KeyReleaseMask);

/*:10*/
#line 58 "unsaver.w"
;
/*11:*/
#line 140 "unsaver.w"

move= 1;
for(;;){
if(g_got_sig!=0){
printf("Got signal %d. Terminating\n",g_got_sig);
break;
}
XWarpPointer(dpy,None,None,0,0,0,0,
move*move_const,move*move_const);
XFlush(dpy);
if(move==1){
move= -1;
}else{
move= 1;
}
sleep(sleep_amt);
}
/*:11*/
#line 59 "unsaver.w"
;
return 0;
}

/*:5*/
