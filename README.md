# CSkaoyan

## 计算机考研学习

---

### 数据结构

#### 第一章至第三章

略

#### 第四章 串

1. ***朴素模式匹配算法：***
    - 字符串模式匹配：在主串中找到与模式串相同的子串，并返回其所在位置
    - 子串--主串的一部分，一定存在
    - 模式串--不一定能在主串中找到
**注：**
**主串长度为n，模式串长度为m**
朴素模式匹配算法:将主串中**所有长度为m的子串**依次与模式串对比，直到找到一个完全匹配的子串，或所有子串都不匹配为止。
**最多对比n-m+1个子串**
