from os import getenv
import brawlstats
from jinja2 import Template

client = brawlstats.Client(getenv('BS_TOKEN'))

player = client.get_profile(getenv('PLAYER_TAG')) # get profile

brawlers = len(player.brawlers)

template = Template(open('sketch_template.ino', 'r').read()).render(
    player=player,
    brawlers=brawlers
) # render the jinja template with the data inside

open('sketch/sketch.ino', 'w+').write(template) # write to the file to be uploaded