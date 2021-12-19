fdfsdafsa
# day 01
*java 基础*
1. 函数
2. 访问权限
3. 类
4. 重写
5. Serializable接口
> 用于实现java中的序列化(`implements Serializable`)
>
> **serialVersionUID**
>
> 数据序列化(二进制化)的标记
>
> > 有持久化与逆持久化
> >
> > 通过ObjectOutputStream/ObjectInputStream类实现具体的目标
> >
> > - objectOUtputStream/持久化
> > ```
> > ObjectOutputStream  ops = new ObjectOutputStream(new FileOutputStream("./src/test.txt"));
> > ops.writeObject(tp);
> > ops.close();
> > ```
> > - objectInputStream/逆持久化
> > ```
> > ObjectInputStream ips = new ObjectInputStream(new FileInputStream("./src/test.txt"));
> > pp t = (pp) ips.readObject();
> > ips.close();
> > ```
> >
6. 连接数据库
> - 加载驱动(MySql)
> ```
> Class.forName("com.mysql.cj.jdbc.Driver");
> ```
> - 连接数据库
> ```
> String dburl = "jdbc:mysql://localhost:3306/dreaife";
> con = DriverManager.getConnection(dburl, "dreaife", "20011223hqs12");
> stmt = con.createStatement();
> ```
> - 发送SQL语句
> ```
> String SQL;
> res = stmt.executeQuery(sql);//查询语句
> res = stmt.executeUpdate(sql);//删改查
> ```
> - 关闭连接
> ```
> if(stmt!=null) stmt.close();
> if(con!=null) con.close();
> if(res!=null) res.close();
> ```

# day02

- 通过数据库实现登录

> 数据库执行过程
> 1. SQL语句
> 2. 执行计划
> 3. 执行执行计划

```
select * from tbName where username = 'name' AND password = 'password';
ResualSet res = stmt.execQuerry(sql);
if(res.next()) sout(success);// 判断查询结果是否为空
else sout(failed);
```

***通过拼接的SQL语句1.有安全隐患 2.效率低***

***通过sql语句预处理类PreparedStatement替换Statement类可以有效避免***

其具体使用方式为：

```
String sql = "select * from t_user where username = ? and password = ?;";
stmt = con.prepareStatement(sql);
stmt.setString(1,name);
stmt.setString(2,password);
```

先对pstmt输入要预编译的SQL语句，对于需要更改替换的地方用`?`来作为占位符使用。

然后再用`pstmt.setString(index,sql)`来对其进行更改以此进行对SQL语句的预处理。

# day03

1. jdbc工具类管理

> - 加载驱动
> ```
>     static{
>         try {
>             Class.forName(driverClass);
>         } catch (ClassNotFoundException e) {
>             e.printStackTrace();
>         }
>     }
> ```
> - 创建连接
> ```
>    public static Connection getConn() throws SQLException {
>         Connection conn = null;
>         conn = DriverManager.getConnection(url,user,password);
>         return conn;
>     }
> ```
> - 关闭连接
> ```
>     public static void closeConn(Connection conn){
>         if(conn != null){
>             try {
>                 conn.close();
>             } catch (SQLException e) {
>                 e.printStackTrace();
>             }
>         }
>     }
> ```
> ***注意，可以使用`private test.jdbcTools(){}`使该类不能实例化，从而使其调用静态成员函数***
>
> ==========================================
>
> - 属性文件*.properties
>
> 内容：key=value;
>
> ***注意！！！该文件需放到src文件夹下，或将所在文件夹设置为sources root，否则无法找到。***
>
> 类 properties 获取属性文件的键值对
>
> ```
>     Properties prop = new Properties();
>         try {
>             prop.load(test.jdbcTools.class.getClassLoader().getResourceAsStream("db.properties"));
>             driverClass = prop.getProperty("jdbc.driverClass");
>             url = prop.getProperty("jdbc.url");
>             user = prop.getProperty("jdbc.user");
>             password = prop.getProperty("jdbc.password");
>         } catch (IOException e) {
>             e.printStackTrace();
>         }
> ```
>
> - 池化技术/连接池解决大量连接
    > (单例)
>
> DBCP C3P0
>
> ```
> private  static BasicDataSource dataSource = new BasicDataSource();
> 
>       dataSource.setDriverClassName(driverClass);
>       dataSource.setUrl(url);
>       dataSource.setUsername(user);
>       dataSource.setPassword(password);
> 
>       dataSource.setInitialSize(initialSize);
>       dataSource.setMaxActive(maxActive);
>       dataSource.setMaxWait(maxWait);//最大等待时间
>       dataSource.setMaxIdle(maxIdle);//最大空闲数
> 
>       Connection conn =  dataSource.getConnection();
> ```
>
## day04
注释

```
String sql = "... ? ...";
Connection con = null;
con = jdbcutil.getCon();
PreparedStatement pstmt = con.createStatement(sql);

pstmt.setString(index,'?');
pstmt.setInt(index,'?');

pstmt.excuteUpdate();
//Or pstmt.excuteQuerry();

jdbcutil.closeCon(con);
```

1. 单元测试

new SourceFolder

Junit4 test case

`@Test` 注解运行,单元测试

可以单独运行,测试与功能分离

```
/**
 * func
 * @param ***(输入变量)
 * @return ***(返回值类型)
 * @throws **Exception(抛出异常类型)
 */
sout testFunc()...;
User new;
try{
	dao.func()//功能的调用
	sout 正常;
}catch(Exception e){
	e.print();
	sout 故障;
}
```

`user.set***(res.get***("***"));`