import bisect
import time
from hashlib import sha512

import codeforces_api
import requests

API_KEY = 'f9809367e3a7750dfbd7b51329a531b268e63cab'
SECRET = '3cbb48b2170f2a58be7b93fec48f3e04df615624'

auth = codeforces_api.CodeforcesApi(API_KEY, SECRET)
parser = codeforces_api.CodeforcesApi()

sub = codeforces_api.CodeforcesParser()

fin = ""


def get_user_info(contestId):
    return parser.contest_status(contest_id=contestId)


# lst = get_user_info('1860')
f = open("output.txt", "a")
# print(lst[0])
# lst1 = parser.user_rated_list(active_only=True)
# lst2 = []
# for i in lst1:
#     if (int(i.max_rating) >= 800 and int(i.max_rating) <= 1000):
#         print(i.handle)
#         lst2.append(i.handle)
#         f.write(i.handle+' ')
# sorted(lst2)
# f.close()
# print(len(lst2))


for i in lst2:
    tmp = parser.user_status(handle=i)
    code = sub.get_solution(contest_id=tmp[0].contest_id,
                            submit_id=tmp[0].id)

    try:
        code.index(fin)
    except ValueError:
        print("Not found!")
    except Exception as e:
        print(e)
        time.sleep(20)
    else:
        print("Found!")
        print(tmp[0].id)
