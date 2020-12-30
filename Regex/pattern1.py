import re

# Type : 년 월 일
text = "해당 날짜는 2020년 12월 31일 입니다."
pattern = r"\d+년 \d+월 \d+일"
result = re.search(pattern, text).group()


# Type : 특수문자 X
text = "asd#qweh^dj18!@#)(*&^d,a/\a"
result = re.sub("[-=+,#/\?:^$.@*\"※~&%ㆍ!』\\‘|\(\)\[\]\<\>`\'…》]", "", text)


# Type : 전화번호
text = "My Phone Number is 010-1234-5678 ..."
pattern = r"\d{2,3}-\d{3,4}-\d{4}"
result = re.search(pattern, text).group()

