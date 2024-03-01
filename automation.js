allbutton = document.getElementsByClassName("artdeco-button artdeco-button--2 artdeco-button--secondary ember-view")
for(let i = 0; i < allbutton.size; i++)
{
    childval = allbutton[i].children[0]; 
    if(childval.textContent.trim() != "Connect") continue; 
    else {
        allbutton[i].click(); 
        document.getElementsByClassName("artdeco-button artdeco-button--2 artdeco-button--primary ember-view ml1")[0].click(); 
    }           
}

