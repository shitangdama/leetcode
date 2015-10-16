The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
Note:
The read function will only be called once for each test case.
Solution: This seemingly easy coding question has some tricky edge cases.0When read4 returns less than 4, we know it must reached the end of file. However, take note that read4 returning 4 could mean the last 4 bytes of the file. To make sure that the buffer is not copied more than n bytes, copy the remaining bytes (n ¨C readBytes) or the number of bytes read, whichever is smaller.