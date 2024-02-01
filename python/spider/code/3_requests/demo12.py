import requests

r = requests.get('http://www.zhihu.com')
exit() if not r.status_code == requests.codes.ok else print('Request Successfully')