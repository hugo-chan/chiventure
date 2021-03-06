#
# Sample proof-of-concept yaml file
#

GAME:
 - start: "room A"
   intro: "This is the intro"
   end:
     - in_room: "room C"

ROOMS:
 - id: "room A"
   short_desc: "This is room A"
   long_desc: "This is room A. There's a chair and an exit to the south."
   connections:
    - to: "room B"
      direction: "SOUTH"

 - id: "room B"
   short_desc: "This is room B"
   long_desc: "This is room B. There's a table and an exit to the west."
   connections:
    - to: "room C"
      direction: "WEST"

 - id: "room C"
   short_desc: "This is room C"
   long_desc: "This is room C, the final room in the game"
   connections:
    - to: "room A"
      direction: "NORTH"

ITEMS:
 - id: "CHAIR"
   short_desc: "This is a chair"
   long_desc: "This is a chair long"
   in: "room A"
   actions: 
    - action: "PUSH"
      text_success: "You push the chair"
      text_fail: "You cannot push this chair"
    - action: "PULL" 
      text_success: "You pull the chair"
      text_fail: "You cannot pull this chair"
    - action: "TAKE"
      text_success: "You take the chair"
      text_fail: "You cannot take this chair"


 - id: "TABLE"
   short_desc: "This is a table"
   long_desc: "This is a table long"
   in: "room B"
   actions:
    - action: "PUSH"
      text_success: "You push the table"
      text_fail: "You cannot push this table"
    - action: "PULL"
      text_success: "You pull the table"
      text_fail: "You cannot pull this table"
    - action: "TAKE"
      text_success: "You take the table"
      text_fail: "You cannot take this table"