#ifndef _BT_H
#define _BT_H

typedef  struct  TelemType {        //本行的TelmType可以不写或为其他名字
	char  name[20];                 //假设字符数组长度为20。
	int   number;
} TelemType; 

typedef  struct  BitNode{          //定义一个结构体新类型，名为BitNode，内含一个TelmType类
	TelemType  data;               //型成员name和两个指向自己类型的指针成员lch和rch；同时，
	struct  BitNode  *Lch,  *Rch;  //指向这种新结构体类型的指针的类型，取名为BiTree。注意，
} BiTNode,  *BiTree;               //BitNode和BiTree都是类型名字，不是变量名！

#endif