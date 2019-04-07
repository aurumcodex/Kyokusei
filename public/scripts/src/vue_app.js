// vue_app.js

Vue.component('menu_list', 
    {
        props: ['thing'],
        template: '<li>{{ thing.text }}</li>'
    }
);

var list = new Vue({
    el: '#list',
    data: {
        listItems: [
            {id: 0, text: 'list item 1'},
            {id: 1, text: 'list item 2'},
            {id: 2, text: 'list item 3'},
            {id: 3, text: 'list item 4'},
        ]
    }
});

console.log("i'm in the console, printin' a thing");