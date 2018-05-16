## 使用说明：

demo/Gromah OJ.exe 是可执行文件。

由于是用 Win8 下的 Qt 做的，屏幕最大分辨率就是 1366×768，所以用之前请先把屏幕分辨率调成 1366×768，不然界面会十分鬼畜。

Host 配置可以是 Gromah 的服务器（Host：???，User：root，Password：gromah），得和我在同一个局域网里才能连我。。也可以是大家本地的服务器 localhost，但是可能要设置一下访问权限：

1.GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY 'xxx' WITH GRANT OPTION;（localhost 可以使用 root 用户，密码为 xxx 访问所有的数据库）

2.flush privileges;

## 配置说明：

管理员账号是 admin，即名字叫做 admin 的账户自动获得管理权限。

表格里面有些东西点开是会弹出窗口的，比如点 Problem 的“Enter”键或者 Status 的 Problem Id 那一列都可以查看题目。

然后我设了一个连点最小时间间隔，这样做是为了防止用鼠标连点器之类的狂点按钮导致 crash。

每个用户还可以对自己的 Status 点击“Show Answer”查看自己提交过的答案，然后还可以在 RankList 点击“Orz”来对其他用户进行 Orz。

两个关于 Orz 的设定：登陆了的用户不能 Orz 自己，当然万能的管理员 admin 除外；Orz 次数统计上限是 233。

然后一个要注意的就是：改题如果改了答案，之前的提交是并不会重测的。

此外因为是用的 mySQL 的 VARCHAR 来存东西，所以输入什么东西的时候不要带半角单引号 ' ，不然会我的程序会语法错误。。

其他的应该都可以自己很快摸索出来。

## 其他想说的：

由于是第一次写这种东西，代码架构比较杂乱无章，还请各位大佬多多批评指正。

然后有什么问题或者想法也欢迎与我交流。
