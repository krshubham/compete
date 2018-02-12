// let i = 1;


// function checker(){
// 	if(i > 1000000007){
// 		return;
// 	}
// 	document.getElementsByName('answer')[0].value = i;
// 	console.log(i);
// 	i++;
// 	setTimeout(() => {
// 		document.getElementsByClassName('button-primary')[0].click();
// 	},500)
// }

// setInterval(checker,2000);


// // $(document).ready(function(){
// //     $('<form action="form2.html"></form>').appendTo('body').submit();
// // });


let i = 1;
function checker(){
	let form = document.querySelector('form');
	form.elements.answer.value = i;
	i++;
	axios.post('/k/gordianknot/api/questions/2/answer',Array.from(new FormData(form).entries(),
		e => e.map(encodeURIComponent).join('=')).join('&'))
	.then(result => {
		// console.log("the value is:",i);
		if(result.data.status === true){
			alert(i);
		}
		console.log(result.data.status)
	})
	.catch(err => console.log(err));
}
999988248
setInterval(checker,500);