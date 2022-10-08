<?php
class bbcode {

static function collect($value = '')
{
$value = preg_replace_callback('~\\[url=(https?://.+?)\\](.+?)\\[/url\\]|(https?://(www.)?[0-9a-z\.-]+\.[0-9a-z]{2,6}[0-9a-zA-Z/\?\.\~&amp;_=/%-:#]*)~', 'process_url', $var);
$value = preg_replace('#@([\w\d]{2,})#si', '@<a href="../@$1">$1</a>', $var); 
$var = preg_replace('#\[color=(.+?)\](.+?)\[/color]#si', '$2', $var);
$value = preg_replace('!\[bg=(#[0-9a-f]{3}|#[0-9a-f]{6}|[a-z\-]+)](.+?)\[/bg]!is', '$2', $var);
$add = array(
'[small]' => '',
'[/small]' => '',
'[big]' => '',
'[/big]' => '',
'[green]' => '',
'[/green]' => '',
'[red]' => '',
'[/red]' => '',
'[blue]' => '',
'[/blue]' => '',
'[b]' => '',
'[/b]' => '',
'[i]' => '',
'[/i]' => '',
'[u]' => '',
'[/u]' => '',
'[s]' => '',
'[/s]' => '',
'[quote]' => '',
'[/quote]' => '',
'[c]' => '',
'[/c]' => '',
'[*]' => '',
'[/*]' => '',
'[spoiler]' => '',
'[/spoiler]' => ''
);
return strtr($value, $add);
}


private static function clean($value)
{
$go = array(
'#\[b](.+?)\[/b]#is',                                              

'#\[i](.+?)\[/i]#is',                                           

'#\[u](.+?)\[/u]#is',                                              

'#\[s](.+?)\[/s]#is',                                              

'#\[small](.+?)\[/small]#is',                                      

'#\[big](.+?)\[/big]#is',                                          

'#\[red](.+?)\[/red]#is',                                         

'#\[green](.+?)\[/green]#is',                                   

'#\[blue](.+?)\[/blue]#is',                                        

'!\[color=(#[0-9a-f]{3}|#[0-9a-f]{6}|[a-z\-]+)](.+?)\[/color]!is', 

'!\[bg=(#[0-9a-f]{3}|#[0-9a-f]{6}|[a-z\-]+)](.+?)\[/bg]!is',       

'#\[(quote|c)](.+?)\[/(quote|c)]#is',                              // Цитата
'#\[\*](.+?)\[/\*]#is'                                   
);


$add = array(
'<span style="font-weight: bold">$1</span>',                       
'<span style="font-style:italic">$1</span>',                  
'<span style="text-decoration:underline">$1</span>',          
'<span style="text-decoration:line-through">$1</span>',            
'<span style="font-size:x-small">$1</span>',               
'<span style="font-size:large">$1</span>',                         
'<span style="color:red">$1</span>',                       
'<span style="color:green">$1</span>',                      
'<span style="color:blue">$1</span>',                  
'<span style="color:$1">$2</span>',               
'<span style="background-color:$1">$2</span>',        
'<span class="quote" style="display:block">$2</span>',           
'<span class="bblist">$1</span>');
return preg_replace($go, $add, $value);
}
}
?>
