from cfg_boost_module import json_parser
import json

configfile = open("engine.json")
jsonconfig = json.load(configfile)

print(json_parser(json.dumps(jsonconfig)))