#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSGKEY 654321L

struct msgbuf1 {		
	long mtype;
	char mtext[512];
} sndbuf, *msgp;		/* message buffer es pointere */



int main()
{
	int id;
	key_t key;
	int flag;
	int rtn, size;
	
	key = MSGKEY;
	flag = 00666 | IPC_CREAT;
	msgid = msgget( key, msgflg);
 	if ( id == -1) {
 	    perror("\n Az msgget hivas nem valosult meg");
 	    exit(-1);
 	}

	printf("\n Az msgid %d, %x : ", msgid,msgid);

	msgp = &sndbuf;
	msgp->mtype = 1;
 	strcpy(msgp->mtext,"Egyik uzenet");
	size = strlen(msgp->mtext) + 1;


	rtn = msgsnd(id,(struct msgbuf *) msgp, size, flag);
	printf("\n Az 1. msgsnd visszaadott %d-t", rtn);
	printf("\n A kikuldott uzenet: %s", msgp->mtext);

	strcpy(msgp->mtext,"Masik uzenet");
	size = strlen(msgp->mtext) + 1;
	rtn = msgsnd(id,(struct msgbuf *) msgp, size, flag);
	printf("\n A 2.msgsnd visszaadott %d-t", rtn);
	printf("\n Az uzenet: %s", msgp->mtext);
	printf("\n");

	exit (0);
}