#include<stdio.h>
#include<sys/types.h>
#include<pwd.h>

void struct_print(struct passwd *s){
	if((s==NULL)||((s->pw_uid>=1000)&&(s->pw_uid))){
		printf("user not exsist\n");
	}else if(s->pw_uid<=1000&&s->pw_uid != 0){
		printf("Linux service user No Login\n");
	}
	else{
		printf("Username :\t%s\nPassword :\t%s\nUser Id :\t%d\nGroup Id :\t%d\nUser Infor :\t%s\nHome Dir :\t%s\nShell Prog :\t%s\n",s->pw_name,s->pw_passwd,s->pw_uid,s->pw_gid,s->pw_gecos,s->pw_dir,s->pw_shell);
	}
}
int main(int argc,char *argv){
	char *usr = "root";
	struct_print(getpwnam(usr));
	return 0;
}
