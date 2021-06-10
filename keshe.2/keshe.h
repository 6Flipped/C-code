#pragma once

void menu();//菜单

int  my_input(int* a);//输入商品信息（添加）

void save(int a);//新增数据后保存数据(ab+打开)

void save1(int a);//修改数据后保存数据（rb+打开）

void save2(int a);//删除数据后全部重新保存（wb+打开）

void load();//读出数据

int my_chachong(int a, int b);//查重(编号）

void my_add(struct goods* p);//补单(修改库存数量)

int my_search(struct goods* p);//查找货品信息

void name_sort(struct goods* p);//名称排序

int name_search(struct goods* p);//名称查找（折半）

void num_sort(struct goods* p);//按编号选择排序

int num_search(struct goods* p);//编号查找（折半）

void my_del(struct goods* p);//删除信息（删除）

void my_sell();//商品销售

void load1();//总查询