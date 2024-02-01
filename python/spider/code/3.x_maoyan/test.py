import requests
import re

def get_one_page(url):  
    headers = {
        'User-Agent': 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)',
        'Cookie':'__mta=251016121.1705284786918.1705284877637.1705284901675.4; uuid_n_v=v1; uuid=9E7AEF80B34B11EE9BB767378F83FFD5AED86B823FC1444AA0D81A4DA5B27E72; _csrf=03ffe741b62e751e0e19510fff63a9e056fa80c0b9b84cc019bb88156a631667; _lxsdk_cuid=18d0ae4d846c8-00a16d2ba9d12c8-b7e2537-1fa400-18d0ae4d846c8; _lxsdk_s=18d0ae4d846-94b-161-30b%7C%7C14; _lxsdk=9E7AEF80B34B11EE9BB767378F83FFD5AED86B823FC1444AA0D81A4DA5B27E72; Hm_lvt_703e94591e87be68cc8da0da7cbd0be2=1705284787; Hm_lpvt_703e94591e87be68cc8da0da7cbd0be2=1705284902; WEBDFPID=64vzxwxx2y9z54181w2937250vw0u45z81w9zv4zy5x97958051z95x6-2020644840295-1705284839309GWAAGOK2960edaad10e294fa6f28397fe2285901593; token=AgF3JCZH00jMB9lvmcltA6n9tvfv4M41b_ZuhcFfnVfysgujLyACvgho3576cS792z2Sc6AG5dfNMQAAAABjHQAAJtKeaQNDwNHDg2eyUTroz4nVOtNzRZmDnPZmEIq1sEd713RWe4ldlha2Kc2rO6Ll; uid=3281096926; uid.sig=5NwMBJ39U9LoJzuPYGgAlemZ61w'
    }

    response = requests.get(url,headers=headers)  
    if response.status_code == 200:  
        return response.text  
    return None  

def parse_one_page(html):
    pattern = re.compile('<i>.*?board-index.*?>(.*?)</i>',re.S)
    items = re.findall(pattern,html)
    for item in items:
        # yield {'index': item[0],
        #     'image': item[1],
        #     'title': item[2].strip(),
        #     'actor': item[3].strip()[3:] if len(item[3]) > 3 else '',
        #     'time': item[4].strip()[5:] if len(item[4]) > 5 else '',
        #     'score': item[5].strip() + item[6].strip()}
        print(item[0])

def main():  
    url = 'http://maoyan.com/board/4'  
    html = get_one_page(url)
    

    print(html)
    parse_one_page(html)


main()