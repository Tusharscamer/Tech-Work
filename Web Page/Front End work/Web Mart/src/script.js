let search=document.getElementById("search");
let searchIcon=document.getElementById("search-icon");
searchIcon.addEventListener("click",function(){
    search.classList.remove("hidden");
    searchIcon.classList.add("hidden");
});
const appContainer = document.getElementById('app-container');
const numberOfApps = 7;
const apps = [
    { imgSrc: 'image/apps/facebook.png', appName: 'Facebook' , appRating :'4.5'},
    { imgSrc: 'image/apps/instalite.png', appName: 'Instalite', appRating :'4.0'},
    { imgSrc: 'image/apps/meesho.png', appName: 'Meesho'  , appRating :'4.0'},
    { imgSrc: 'image/apps/phonepe.png', appName: 'PhonePe'  , appRating :'4.5'},
    { imgSrc: 'image/apps/snapchat.png', appName: 'Snapchat'  , appRating :'4.0'},
    { imgSrc: 'image/apps/truecaller.png', appName: 'Truecaller'  , appRating :'4.0'},
    { imgSrc: 'image/apps/whatsapp.png', appName: 'Whatsapp'  , appRating :'4.0'},
  ];
  apps.forEach(app => {
    // Create the app div
    const appDiv = document.createElement('div');
    appDiv.classList.add('app', 'flex', 'flex-col');
  
    // Create and append img
    const img = document.createElement('img');
    img.src = app.imgSrc;
    img.alt = `${app.appName} Logo`;
    img.classList.add('w-32', 'h-32');
    appDiv.appendChild(img);
  
    // Create and append app name
    const appName = document.createElement('span');
    appName.textContent = app.appName;
    appDiv.appendChild(appName);
  
    // Create and append rating container
    const ratingContainer = document.createElement('span');
    ratingContainer.classList.add('space-x-2');
  
    // Create and append rating text
    const ratingText = document.createElement('span');
    ratingText.textContent = app.appRating;
    ratingContainer.appendChild(ratingText);
  
    // Create and append star icon
    const starIcon = document.createElement('i');
    starIcon.classList.add('fa-solid', 'fa-star');
    ratingContainer.appendChild(starIcon);
  
    appDiv.appendChild(ratingContainer);
  
    appContainer.appendChild(appDiv);
  });

  let edchoiceContainer = document.getElementById('editorTool-container');
  
  const editorTools = [
      { imgSrc: 'image/editorsChoice/hotstar.png', appName: 'Hotstar' , appRating :'4.5'},
      { imgSrc: 'image/editorsChoice/inshot.png', appName: 'Inshot', appRating :'4.0'},
      { imgSrc: 'image/editorsChoice/picart.png', appName: 'Picart'  , appRating :'4.0'},
      { imgSrc: 'image/editorsChoice/swiggy.png', appName: 'Swiggy'  , appRating :'4.5'},
      { imgSrc: 'image/editorsChoice/telegram.png', appName: 'Telegram'  , appRating :'4.0'},
      { imgSrc: 'image/editorsChoice/zomato.png', appName: 'Zomato'  , appRating :'4.0'},
      { imgSrc: 'image/editorsChoice/zoom.png', appName: 'Zoom'  , appRating :'4.0'},
    ];
    editorTools.forEach(editorTools => {
      // Create the app div
      const edappDiv = document.createElement('div');
      edappDiv.classList.add('app', 'flex', 'flex-col','p-2','justify-center','items-center','shadow-lg','shadow-slate-150');
    
      // Create and append img
      const img = document.createElement('img');
      img.src = editorTools.imgSrc;
      img.alt = `${editorTools.appName} Logo`;
      img.classList.add('w-28', 'h-28');
      edappDiv.appendChild(img);
    
      // Create and append app name
      const appName = document.createElement('span');
      appName.textContent = editorTools.appName;
      edappDiv.appendChild(appName);
    
      // Create and append rating container
      const ratingContainer = document.createElement('span');
      ratingContainer.classList.add('space-x-2');
    
      // Create and append rating text
      const ratingText = document.createElement('span');
      ratingText.textContent = editorTools.appRating;
      ratingContainer.appendChild(ratingText);
    
      // Create and append star icon
      const starIcon = document.createElement('i');
      starIcon.classList.add('fa-solid', 'fa-star');
      ratingContainer.appendChild(starIcon);
    
      edappDiv.appendChild(ratingContainer);
    
      edchoiceContainer.appendChild(edappDiv);
    });
  
  

    const spvContainer = document.getElementById('spv-container');
  
    const spv = [
        { imgSrc: 'image/spv/hipi.png', appName: 'Hipi' , appRating :'4.5'},
        { imgSrc: 'image/spv/instalite.png', appName: 'Insta Lite', appRating :'4.0'},
        { imgSrc: 'image/spv/moj.png', appName: 'Moj'  , appRating :'4.0'},
        { imgSrc: 'image/spv/pinterest.png', appName: 'Pinterest'  , appRating :'4.5'},
        { imgSrc: 'image/spv/snapchat.png', appName: 'Snapchat'  , appRating :'4.0'},
        { imgSrc: 'image/spv/tango.png', appName: 'Tango'  , appRating :'4.0'},
        { imgSrc: 'image/spv/thread.png', appName: 'Thread'  , appRating :'4.0'},
      ];
      spv.forEach(spv => {
        // Create the app div
        const spvappDiv = document.createElement('div');
        spvappDiv.classList.add('app', 'flex', 'flex-col','p-2','justify-center','items-center');
      
        // Create and append img
        const img = document.createElement('img');
        img.src = spv.imgSrc;
        img.alt = `${spv.appName} Logo`;
        img.classList.add('w-32', 'h-32');
        spvappDiv.appendChild(img);
      
        // Create and append app name
        const appName = document.createElement('span');
        appName.textContent = spv.appName;
        spvappDiv.appendChild(appName);
      
        // Create and append rating container
        const ratingContainer = document.createElement('span');
        ratingContainer.classList.add('space-x-2');
      
        // Create and append rating text
        const ratingText = document.createElement('span');
        ratingText.textContent = spv.appRating;
        ratingContainer.appendChild(ratingText);
      
        // Create and append star icon
        const starIcon = document.createElement('i');
        starIcon.classList.add('fa-solid', 'fa-star');
        ratingContainer.appendChild(starIcon);
      
        spvappDiv.appendChild(ratingContainer);
      
        spvContainer.appendChild(spvappDiv);
      });
    
    
      let main = document.querySelector('main');
      main.addEventListener('click', function () {
        search.classList.add('hidden');
        searchIcon.classList.remove('hidden');
      });