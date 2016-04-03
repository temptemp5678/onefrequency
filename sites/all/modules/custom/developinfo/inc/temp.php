$exec2 =  exec('cd /Applications/AMPPS/www/lillydash/sites/default/files/phantomjs/bin/');
dpm($exec2);

$exec =  exec('pwd');
dpm($exec);

$exec =  exec('whoami');
dpm($exec);

$response = exec('/Applications/AMPPS/www/lillydash/sites/default/files/phantomjs/bin/phantomjs responsive-screenshot-demo.js http://lambdathemes.in/admin1/');
dpm($response);

$response = exec('/Applications/AMPPS/www/lillydash/sites/default/files/phantomjs/bin/phantomjs sample/sample.js');
dpm($response);


export PATH="$PATH:/Applications/AMPPS/www/lillydash/sites/default/files/phantomjs/bin/"
