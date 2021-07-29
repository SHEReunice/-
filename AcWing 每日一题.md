# AcWing 每日一题



## AcWing 3763. 数字矩阵

给定一个 n×mn×m 的整数矩阵，其中第 ii 行第 jj 列的元素为 aijaij。

你可以进行任意多次如下操作：

选择矩阵中的两个相邻元素，将它们均乘以 −1−1。

同一个元素可以被选中多次。

你需要通过上述操作，使得矩阵中所有元素的和尽可能大。

计算并输出这个和的最大可能值。

### **输入格式**

第一行包含整数 TT，表示共有 TT 组测试数据。

每组数据第一行包含两个整数 n,mn,m。

接下来 nn 行，每行包含 mm 个整数，表示整个矩阵，其中第 ii 行第 jj 列的数为 aijaij。

### **输出格式**

每组数据输出一行结果，表示矩阵的所有元素的最大可能和。

### **数据范围**

1≤T≤1001≤T≤100,2≤n,m≤102≤n,m≤10,−100≤aij≤100−100≤aij≤100

### **输入样例：**

```cpp
2
2 2
-1 1
1 1
3 4
0 -1 -2 -3
-1 -2 -3 -4
-2 -3 -4 -5
```

### 输出样例：

```cpp
2
30
```

### 思路：

- 不管相隔多远的两个数，都可以在它们的路径上一直取两个数乘-1，使路径上的数值不变，这两个数变为原来的相反数，如果负数的个数为奇数个，那就留下所有数中绝对值最小的那个数最为最后的负数；
- 所以在输入的时候就把所有数的绝对值相加得到sum，如果负数个数为偶数个，那答案就是sum；如果负数个数为奇数个，记最后留下的那个绝对值最小数的绝对值为min，（不一定原来是负数，原来可能是正数，但它绝对值最小所以留下作为最后的负数）为min,所以答案应该为sum-2*min（因为一开始也把它加进去了）
- 如果负数是奇数个，但是所有数中含有0（可以让那个负数和0一起乘-1变为正数），也没有关系因为在用绝对值进行比较的时候，0将会作为绝对值最小的那个数保留下来，sum-2*0还是sum

### 代码

```cpp
#include <iostream>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 
 int T;
int main(){
	cin >> T;
	while(T--){
		int a[15][15];
		int n,m;
		int sum = 0, min=1e8, cnt = 0;
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
				sum += abs(a[i][j]);
				if(a[i][j] < 0){
					cnt++;
				}
				if(abs(a[i][j]) < min){
						min = abs(a[i][j]);
					}			
			}
		}
		if(cnt % 2 == 0){
			cout << sum << endl;
		}else{
			cout << sum - 2*min << endl;
		}
	}
	return 0;
	
}
```

## **AcWing  3764.三元数异或**

如果一个整数，其各个数位不包含 0,1,20,1,2 以外的数字，则称这个数为三元数。

例如，1022,11,21,20021022,11,21,2002 都是三元数。

给定一个可能很长的三元数 xx，其首位数字（最左边那位）保证为 22，其他位数字为 00 或 11 或 22。

我们规定，两个长度为 nn 的三元数 aa 和 bb 可以通过三元异或运算 ⊙⊙ 得到另一个长度为 nn 的三元数 cc。

设 ai,bi,ciai,bi,ci 分别表示 a,b,ca,b,c 的第 ii 位的数字，则 ci=(ai+bi)mod3ci=(ai+bi)mod3。

例如，10222 ⊙ 11021=2121010222 ⊙ 11021=21210。

你的任务是对于每个给定的 xx，求出可以满足 a ⊙ b=xa ⊙ b=x，并且 max(a,b)max(a,b) 尽可能小的 a,ba,b。

注意，a,ba,b 都必须是 nn 位三元数，且不含前导 00。

### **输入格式**

第一行包含整数 TT，表示共有 TT 组测试数据。

每组数据第一行包含整数 nn，表示 xx 的长度。

第二行包含一个长度为 nn，首位为 22 的三元数 xx。

### **输出格式**

每组数据输出占两行，分别包含数 aa 和数 bb。

如果答案不唯一，则输出任意合理答案均可。

### **数据范围**

1≤T≤1041≤T≤104,1≤n≤5×1041≤n≤5×104,同一测试点所有 nn 的和不超过 5×1045×104。

### **输入样例：**

```
4
5
22222
5
21211
1
2
9
220222021
```

### **输出样例：**

```
11111
11111
11000
10211
1
1
110111011
110111010
```

### 思路：

- 可以观察一下示例，我们这里设定a>b，让a是那个较大的数，首先a和b的第一位一定都是1，后面出现0的话，a和b都给0，，后面如果出现第一个1，则为了a>b，（因为是三元异或，也可以都给两者2和2，但是我们要求尽可能小，所以不采用这个分法），则把1给a，0给b，在出现了1之后：出现2，则将0给a，2给b；出现1，0给a，1给b。
- 如果没有一直没有出现1：出现2，1给a，1给b

### 代码

```cpp
#include<iostream>
#include<string.h>
#include<algorithm>
#include <stdio.h>
using namespace std;
char a[50005],b[50005],x[50005];

int main(){
	int T;
	cin >> T;
	int n;
	while(T--){
		cin >> n;
		memset(x,'0',(n+1)); //这里乘4会报分段错误
		memset(a,'0',(n+1));
		memset(b,'0',(n+1));
		int flag = 0;
		string X;
		cin >> X;
		strcpy(x,X.c_str());    //字符串转化为字符数组
		a[0] = '1';
		b[0] = '1';
		for(int i = 0; i < n; i++){
			if(x[i] == '2'){
				a[i] = '1';
				b[i] = '1';
			}else if(x[i] == '0'){
				a[i] = '0';
				b[i] = '0';
			}else{
				a[i] = '1';
				b[i] = '0';
				flag = i;
				break;
			}
		}
		if(flag != 0){
		for(int i = flag+1; i < n; i++){
			if(x[i]=='2'){
					a[i] = '0';
					b[i] = '2';
			}else if(x[i] == '1'){
					a[i] = '0';
					b[i] = '1';
			}else{
				a[i] = '0';
				b[i] = '0';
			}
		}	
		}
		
	
	for(int i = 0; i < n; i++){
		cout << a[i];
	}
	cout << endl;
	for(int i = 0; i < n; i++){
		cout <<b[i];
	}
	cout << endl;
}
return 0;
	
}
```



## **AcWing  3767.最小的值**

给定两个长度为 nn 的 0101 数组 a1,a2,…,ana1,a2,…,an 和 b1,b2,…,bnb1,b2,…,bn。

请你构造一个长度为 nn 的**正整数**数组 p1,p2,…,pnp1,p2,…,pn。

![image-20210729100320359](C:\Users\Eunice\AppData\Roaming\Typora\typora-user-images\image-20210729100320359.png)

输出最小可能值。

### **输入格式**

第一行包含整数 nn。

第二行包含 nn 个整数 a1,a2,…,ana1,a2,…,an。

第三行包含 nn 个整数 b1,b2,…,bnb1,b2,…,bn。

### **输出格式**

输出 maxi=1npimaxi=1npi 的最小可能值。

如果不存在满足条件的数组 pp，则输出 −1−1。

### **数据范围**

1≤n≤1001≤n≤100,0≤ai,bi≤10≤ai,bi≤1

### **输入样例1：**

```
5
1 1 1 0 0
0 1 1 1 1
```

### **输出样例1：**

```
3
```

### **输入样例2：**

```
3
0 0 0
0 0 0
```

### **输出样例2：**

```
-1
```

### **输入样例3：**

```
4
1 1 1 1
1 1 1 1
```

### **输出样例3：**

```
-1
```

### **输入样例4：**

```
9
1 0 0 0 0 0 0 0 1
0 1 1 0 1 1 1 1 0
```

### **输出样例4：**

```
4
```

### 思路：

- p是正整数数组，最小是1，不能为0，当ai和bi相等时，pi就直接是1；当ai小于bi时，pi也是1，记录下所有ai<bi的和，记为sum1，再记录ai>bi有多少对，记为cnt，只要这个sum1分到cnt上，就可以得到满足条件的pi的最大值尽可能小；
- 如果sum1能整除cnt，这个时候得到的pi也只能是满足ai*pi的累和等于bi与pi的累和，所以要加一；如果不能整除，向下取整，所以也要加一

### 代码

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[105],b[105],p[105];

int main(int argc, const char * argv[]) {
    
    int sum = 0;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(a[i] == b[i]){
            p[i] = 1;
        }else if(a[i] < b[i]){
            p[i] = 1;
            sum++;
        }else{
            cnt++;
        }
    }
    if(cnt == 0){
        cout << -1;
    }else{
        cout << sum/cnt + 1;
    }
   
    return 0;
}
```

## AcWing  3768.字符串删减

给定一个由 nn 个小写字母构成的字符串。

现在，需要删掉其中的一些字母，使得字符串中不存在**连续**三个或三个以上的 `x`。

请问，最少需要删掉多少个字母？

如果字符串本来就不存在**连续的**三个或三个以上 `x`，则无需删掉任何字母。

### **输入格式**

第一行包含整数 nn。

第二行包含一个长度为 nn 的由小写字母构成的字符串。

### **输出格式**

输出最少需要删掉的字母个数。

### **数据范围**

3≤n≤1003≤n≤100

### **输入样例1：**

```
6
xxxiii
```

### **输出样例1：**

```
1
```

### **输入样例2：**

```
5
xxoxx
```

### **输出样例2：**

```
0
```

### **输入样例3：**

```
10
xxxxxxxxxx
```

### **输出样例3：**

```
8
```

### 思路：

- 读入所有字母后，遍历数组，只要它自己、它前面一个、它前面的前面是x就把它删掉

### 代码

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char ch[105];
int n;
int cnt=0;

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ch[i];
        if(i>=2 && ch[i] == 'x'){
            if(ch[i-1] == 'x' && ch[i-2] == 'x'){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
```

## **AcWing  3769.移动石子**

一共有 nn 个箱子排成一排，从左到右依次编号为 1∼n1∼n。

其中，第 ii 号箱子中放有 aiai 个石子。

现在，你可以进行最多 dd 次操作。

每次操作可以将一个石子从一个箱子移动至另一个**与其相邻**的箱子里。

我们希望通过合理操作使得 11 号箱子内的石子数量尽可能大。

请问，这个最大可能值是多少？

### **输入格式**

第一行包含整数 TT，表示共有 TT 组测试数据。

每组数据第一行包含两个整数 nn 和 dd。

第二行包含 nn 个整数 a1,a2,…,ana1,a2,…,an。

### **输出格式**

每组数据输出一行结果，表示答案。

### **数据范围**

1≤T≤1001≤T≤100,1≤n,d≤1001≤n,d≤100,0≤ai≤1000≤ai≤100

### **输入样例：**

```
3
4 5
1 0 3 2
2 2
100 1
1 8
0
```

### **输出样例：**

```
3
101
0
```

### 思路：

- 数组下标为i的石子移到第一个位置需要移动i次，所以每次下标为i的位置能移到第一个位置的石子个数最多为d/i，所以从i=1开始，判断石子个数与d/i的大小，同时每个位置判断为之后，d要减去消耗的次数，直到d/i小于当前位置的石子数或者后面的石子都移完了

### 代码

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;

int main(int argc, const char * argv[]) {
    int n,d;
    cin >> T;
    while(T--){
        cin >> n >> d;
        int a[n];
        int flag = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i > 0 && flag == 0 ){
                if(a[i] <= d/i){
                    a[0] += a[i];
                    d = d - a[i] * i;
                }else{
                    a[0] += d/i;
                    flag = 1;
                }
            }
        }
        cout << a[0] << endl;
    }
    return 0;
}
```

## **AcWing 3773. 兔子跳**

一只兔子位于二维平面的原点 (0,0)(0,0) 处，它想通过一系列的跳跃，跳到点 (x,0)(x,0) 处。

给定一个长度为 nn 的数组 a1,a2,…,ana1,a2,…,an。

兔子能从一个点跳到另一个点，当且仅当两点之间的距离等于上述数组中的某个元素的值。

请问，兔子从 (0,0)(0,0) 到 (x,0)(x,0) 最少需要跳几次？

注意，兔子可以跳到非整数坐标的点上。

例如，当 x=4x=4，a={1,3}a={1,3} 时，(0,0)→(1,0)→(4,0)(0,0)→(1,0)→(4,0) 和 (0,0)→(2,5‾√)→(4,0)(0,0)→(2,5)→(4,0) 均为合理最佳方案之一。

### **输入格式**

第一行包含整数 TT，表示共有 TT 组测试数据。

每组数据第一行包含两个整数 nn 和 xx。

第二行包含 nn 个整数 a1,a2,…,ana1,a2,…,an。

### **输出格式**

每组数据输出一行结果，表示最少跳跃次数。

### **数据范围**

1≤T≤10001≤T≤1000,1≤n≤1051≤n≤105,1≤x≤1091≤x≤109,1≤ai≤1091≤ai≤109,aiai 各不相同。保证同一测试点内所有 nn 的和不超过 105105。

### **输入样例：**

```
4
2 4
1 3
3 12
3 4 5
1 5
5
2 10
15 4
```

### **输出样例：**

```
2
3
1
2
```

### 思路：

- 如果x的值与a[]中某个值相等那一定可以一步到达；如果a中没有存在与x相等的数取a中最大的数假设为a[m]，将a[m]与x比较，如果a[m]>x,那一定可以两步到达，（做一个等腰三角形）；如果a[m]<x：若x能整除a[m]，那需要x/a[m]这么多步到达；如果a[m]不能被x整除，那需要x/a[m]+1步：因为x/a[m]是向下取整，最后一步一定小于a[m],前面一步也就是倒数第二步为a[m]，所以最后两步加起来长度小于2*a[m],所以这里一定存在一个腰为a的等腰三角形，所以x/a[m]再多一步一定能到

### 代码

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;

int main(int argc, const char * argv[]) {
    int n,d;
    cin >> T;
    while(T--){
        cin >> n >> d;
        int a[n];
        int flag = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i > 0 && flag == 0 ){
                if(a[i] <= d/i){
                    a[0] += a[i];
                    d = d - a[i] * i;
                }else{
                    a[0] += d/i;
                    flag = 1;
                }
            }
        }
        cout << a[0] << endl;
    }
    return 0;
}
```

## AcWing 3774. 亮灯时长

自习室内有一个智能灯。

在 00 时刻，管理员会将打开电闸，并将灯点亮。

在 MM 时刻，管理员会直接拉下电闸，此时，如果灯处于点亮状态，则会因为断电而熄灭。

在 0∼M0∼M 之间有 nn 个不同时刻，不妨用 a1,a2,…,ana1,a2,…,an 表示，其中 0<a1<a2<…<an<M0<a1<a2<…<an<M。

在这 nn 个时刻中的每个时刻，管理员都会拨动一次智能灯的开关，使灯的状态切换（亮变灭、灭变亮）。

现在，你可以**最多**额外指定一个时刻（也可以不指定），让管理员在此时刻也拨动开关一次。**注意选定的时刻不能与 a1,a2,…,ana1,a2,…,an 相等**。

你的目的是让亮灯的总时长尽可能长。

输出这个最大亮灯总时长。

### **输入格式**

第一行包含整数 TT，表示共有 TT 组测试数据。

每组数据，第一行包含两个整数 nn 和 MM。

第二行包含 nn 个整数 a1,a2,…,ana1,a2,…,an。

### **输出格式**

输出一个整数，表示最大亮灯总时长。

### **数据范围**

1≤T≤301≤T≤30,1≤n≤1051≤n≤105,2≤M≤1092≤M≤109,0<a1<a2<…<an<M0<a1<a2<…<an<M。同一测试点内所有 nn 的和不超过 105105。

### **输入样例：**

```
3
3 10
4 6 7
2 12
1 10
2 7
3 4
```

### **输出样例：**

```
8
9
6
```

### 思路：

- 如果不按，那就是所有的奇数区间亮，a[0]~a[1],a[2]~a[3]....
- 如果在奇数区间按，如果在a[i]~a[i+1]之间按，那就是a[i]之前的奇数区间和a[i+1]之后的偶数区间亮，还有a[i]~a[i+1]中间的亮的一部分，这部分最长是(a[i+1]-a[i]-1)
- 如果在偶数区间按，如果在如果在a[i]~a[i+1]之间按，那就是a[i]之前的奇数区间和a[i+1]之后的偶数区间亮，还有a[i]~a[i+1]中间的亮的一部分，这部分最长是(a[i+1]-a[i]-1)，这和上面那种情况是一样的
- 所有前面那个长度是一样的，所以在枚举的时候直接枚举所有区间，然后取这个区间前面的奇数区间和后面的偶数区间和它自己这里最长的部分
- 利用前缀和的思想，创建一个奇数区间和数组和偶数区间和数组，这样很容易得到a[i]之前的奇数区间和a[i+1]之后的偶数区间和
- 

![截屏2021-07-23上午10.47.59](C:\Users\Eunice\Downloads\截屏2021-07-23上午10.47.59.png)



### 代码

- 我的代码：

```cpp
//
//  main.cpp
//  3774. 亮灯时长
//
//  Created by Eunice on 2021/7/23.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100005],s1[100005],s2[100005];

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        a[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(i % 2 != 0){
                s1[(i+1)/2] = a[i] - a[i-1];
                if(i > 1) s1[(i+1)/2] += s1[(i+1)/2-1];
            }else{
                s2[i/2] = a[i] - a[i-1];
                if(i > 2) s2[i/2] += s2[i/2-1];
            }
        }
        a[n+1] = m;
        if((n+1) % 2 != 0){
            s1[((n+1)+1)/2] = a[(n+1)] - a[n];
            if((n+1) > 1) s1[((n+1)+1)/2] += s1[((n+1)+1)/2-1];
        }else{
            s2[(n+1)/2] = a[(n+1)] - a[n];
            if((n+1) > 2) s2[(n+1)/2] += s2[(n+1)/2-1];
        }
        int res = s1[(n+2)/2];
        for(int i = 1; i <= n+1; i++){  //这里是a[i-1]到a[i]这个区间，所以是a[i-1]之前的奇数区间，a[i]之后的偶数区间
            int t;
            t = a[i] - a[i-1];
            res = max(res, s1[i/2] + s2[(n+1)/2]-s2[i/2] + t-1);  //i-1之前有（i-1+1)/2这么多个奇数区间，比如3之前有两个，0-1，2-3
            //a[i]之后有(n+1)/2-i/2这么多个，比如n=7，4之后有5-6一个偶数区间，4之前有4/2两个偶数区间，7之前有7/2三个偶数区间，所以两个相减就是一个区间
        }
        cout << res << endl;
    }
    return 0;
}
```

- 题解代码：

```cpp
//
//  main.cpp
//  3774. 亮灯时长
//
//  Created by Eunice on 2021/7/23.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int n,m;
int a[N],s1[N],s2[N]; //s1是s奇数区间和，s2是偶数区间和

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
        a[++n] = m;
        s1[n] = s2[n] = 0;
        for(int i = n-1; i >= 0; i--){ //从后往前枚举，后缀和
            s1[i] = s1[i+1];
            s2[i] = s2[i+1];
            if(i % 2 == 0) s1[i] += a[i+1] - a[i];  //奇数区间
            else s2[i] += a[i+1] - a[i];  //偶数区间
        }
        
        int res = s1[0];
        for(int i = 0; i < n; i++){
            int t = a[i+1] - a[i];
            if(t == 1) continue;
            res = max(res, s1[0] - s1[i] + s2[i+1] + t - 1); //按的那部分最长是t-1
        }
        printf("%d\\n",res);
    }
    return 0;
}
```

## AcWing  795.前缀和

输入一个长度为 nn 的整数序列。

接下来再输入 mm 个询问，每个询问输入一对 l,rl,r。

对于每个询问，输出原序列中从第 ll 个数到第 rr 个数的和。

### **输入格式**

第一行包含两个整数 nn 和 mm。

第二行包含 nn 个整数，表示整数数列。

接下来 mm 行，每行包含两个整数 ll 和 rr，表示一个询问的区间范围。

### **输出格式**

共 mm 行，每行输出一个询问的结果。

### **数据范围**

1≤l≤r≤n1≤l≤r≤n,1≤n,m≤1000001≤n,m≤100000,−1000≤数列中元素的值≤1000−1000≤数列中元素的值≤1000

### **输入样例：**

```
5 3
2 1 3 6 4
1 2
1 3
2 4
```

### **输出样例：**

```
3
6
10
```

### 思路：

- 定义一个和数组s,在输入的时候就进行累加，s[i]存的就是a[1]~a[i]的和，注意s[r]和s[l]相减的时候还要加上a[l]

### 代码

```cpp
//
//  main.cpp
//  795. 前缀和
//
//  Created by Eunice on 2021/7/23.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100005],s[100005];

int main(int argc, const char * argv[]) {
    int n;
    int m,ans;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 1) s[i] = s[i-1] + a[i];
        else s[i] = a[i];
    }
    int l,r;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        ans = s[r] - s[l] + a[l];
        cout << ans << endl;
    }
    return 0;
}
```

## Acwing  3776.水果拼盘

某水果店以出售水果拼盘盈利。

该店铺共提供两种拼盘：

- 拼盘1 ：包含 1个苹果，1 个香蕉。
- 拼盘2 ：包含 1个梨，1 个橙子， 1个香蕉。

已知该店铺共有 a 个苹果，b 个梨，c 个橙子，d 个香蕉。

拼盘 1 的利润为 e 元，拼盘 2的利润为 f 元。

水果店的生意很好，所有拼好的拼盘都会销售一空。

请问，利用现有水果拼装水果拼盘，能够获得的最大利润是多少？

注意，也许会有一些水果用不完，但这并不重要。

### **输入格式**

第一行包含整数 T，表示共有 T 组测试数据。

每组数据占一行，包含 6个整数，依次为 a,b,c,d,e,f。

### **输出格式**

每组数据输出一行结果，表示最大利润。

### **数据范围**

1≤T≤10。

1≤a,b,c,d≤10^5,

1≤e,f≤10^3。

### **输入样例：**

```
3
4 5 6 3 1 2
12 11 13 20 4 6
17 14 5 21 15 17
```

### **输出样例：**

```
6
102
325
```

### 思路：

- 先判断拼盘1和2哪个盈利更高，然后比较相应的水果数量，然后注意香蕉的数量

### 代码

```cpp
//
//  main.cpp
//  3776. 水果拼盘
//
//  Created by Eunice on 2021/7/25.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;

int main(int argc, const char * argv[]) {
    scanf("%d ",&T);
    while(T--)
    {
      int a,b,c,d,e,f;
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
        int sum = 0;
        if(f > e)
        {
            int min2 = min(b,c);
            min2 = min(min2,d);
            if(min2 == d)
            { //香蕉都做拼盘2
                sum = d * f;
            }else
            {
                sum += min2 * f;
                d -= min2;
                int min1 = min(a,d);
                sum += min1 * e;
            }
        }else
        {
            int min1 = min(a,d);
            if(min1 == d)
            {
                sum += d * e;
            }else
            {
                sum += min1 * e;
                d -= min1;
                int min2 = min(b,c);
                min2 = min(min2, d);
                sum += min2 * f;
            }
        }
        printf("%d\\n",sum);
    }
    
    return 0;
}
```



## Acwing  3777.砖块

n 个砖块排成一排，从左到右编号依次为 1∼n

每个砖块要么是黑色的，要么是白色的。

现在你可以进行以下操作若干次（可以是 00 次）：

选择两个相邻的砖块，反转它们的颜色。（黑变白，白变黑）

你的目标是通过不超过 3n3n 次操作，将所有砖块的颜色变得一致。

### **输入格式**

第一行包含整数 TT，表示共有 TT 组测试数据。

每组数据第一行包含一个整数 nn。

第二行包含一个长度为 nn 的字符串 ss。其中的每个字符都是 `W` 或 `B`，如果第 ii 个字符是 `W`，则表示第 ii 号砖块是白色的，如果第 ii 个字符是 `B`，则表示第 ii 个砖块是黑色的。

### **输出格式**

每组数据，如果无解则输出一行 −1−1。

否则，首先输出一行 kk，表示需要的操作次数。

如果 k>0k>0，则还需再输出一行 kk 个整数，p1,p2,…,pkp1,p2,…,pk。其中 pipi 表示第 ii 次操作，选中的砖块为 pipi 和 pi+1pi+1 号砖块。

如果方案不唯一，则输出任意合理方案即可。

### **数据范围**

1≤T≤101≤T≤10，2≤n≤2002≤n≤200。

### **输入样例：**

```
4
8
BWWWWWWB
4
BWBB
5
WWWWW
3
BWB
```

### **输出样例：**

```
3
6 2 4
-1
0
2
2 1
```

### 思路：

- 思路是使用递推的方法，在两种情况下，一直翻一直翻，翻到最后如果第一个和最后一个不一样，那就无解了

### 代码

```cpp
//
//  main.cpp
//  3777.砖块
//
//  Created by Eunice on 2021/7/25.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int n;

bool check(string s, char c)
{
    int op[205];
    int j = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(s[i] != c)
        {
            if(s[i] == 'W') s[i] = 'B';
            else s[i] = 'W';
            if(s[i+1] == 'W') s[i+1] = 'B';
            else s[i+1] = 'W';
            op[j++] = i+1;  //存一下操作的地方
        }
    }
    if(s[n-1] != s[0])  return false;
    if (j != 0)cout << j << endl;
    else cout << 0 << endl;
    for(int i = 0; i < j; i++)
    {
        cout << op[i] << " ";
    }
    if(j != 0) cout << endl;  //如果是不需要操作已经满足情况的话，上面已经输出过换行了
    return true;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    while(T--){
        string s;
        cin >> n >> s;
        if(!check(s,'W') && !check(s,'B'))
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
```



## Acwing  3781.乘车问题

n 个班的小朋友乘大巴去郊游，第 i 个班有 ai 个人。

每隔一段时间就会来一辆空大巴车，每个大巴车可以容纳 m 个小朋友。

已知，在安排乘车时，必须按照 1 班，2 班，…，n 班的顺序，依次安排每个班的小朋友。

同一个班的小朋友必须被安排在同一辆车内。

也就是说，如果当前需要安排 ii 班乘坐大巴，而此时大巴剩余的座位数量少于 ai，则让大巴先走，ii 班以及后续班级共同等待下一辆大巴到来。

请问，将所有小朋友接走，共需多少辆大巴？

### **输入格式**

第一行包含整数 T，表示共有 T 组测试数据。

每组数据第一行包含两个整数 n,m。

第二行包含 个整数 a1,a2,…,an。

### **输出格式**

每组数据输出一行结果，表示所需大巴数量。

### **数据范围**

1≤T≤301≤T≤30,1≤n,m≤1001≤n,m≤100,1≤ai≤m1≤ai≤m

### **输入样例：**

```
2
4 3
2 3 2 1
3 4
1 2 1
```

### **输出样例：**

```
3
1
```

### 思路：

- 注意两个小问题：
  - 在tmp更新的时候车辆也要加一
  - 最后一次直接装下小朋友，在最后记得车辆加一

### 代码

```cpp
#include <iostream>
using namespace std;

int T;
int n,m;
int a[105];
int main()
{
	
	cin >> T;
	while(T--)
	{
	cin >> n >> m;
	int tmp = m;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] > tmp)
		{
			tmp = m;
			ans++;
			tmp -= a[i];
		}else
		{
			tmp -= a[i];
		}
	}
	ans++; 
	cout << ans << endl;	
	}
	 }
```