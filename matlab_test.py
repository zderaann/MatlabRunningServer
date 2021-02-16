import os
import requests


request_dict = {"a": 4, "b": 3}
url = "http://192.168.56.1:9099/api/matlab_run_cmd"

response = requests.post(url, request_dict)

print(response.json())
