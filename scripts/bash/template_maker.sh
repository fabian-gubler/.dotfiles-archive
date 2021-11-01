#! /bin/bash
# script to auto-generate html templates.
# create alias and link to this script.

name=("$@")

# HTML boiler function
htmlPage() {
cat << EOF >> index.html
<!DOCTYPE html>
<html>
  <head>
    <title>${name}</title>
    <link rel=”stylesheet” href=”css/style.css”>
    <meta name=”viewport” content=”width=device-width, initial-scale=1.0">
  </head>
  <body>
    <script src=”js/script.js”></script>
  </body>
</html>
EOF
}


# Create Files and Directories
mkdir ${name}
cd ${name}
mkdir css js
touch index.html css/style.css js/script.js
htmlPage
