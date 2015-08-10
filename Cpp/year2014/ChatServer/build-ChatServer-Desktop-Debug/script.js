var timer;
var myId;
var colors = ["black", "red", "green", "blue", "yellow", "pink", "purple", "orange", "#696969", "969696", "123123", "321321"];

function scrollMessages() {
	var wd = $('#messages')[0].scrollHeight;
	$('#messages').parent().scrollTop(wd);
}

function wrap(val, nums) {
	var ret = "" + val;
	while (ret.length < nums) ret = "0" + ret;
	return ret;
}

function appendMessage(messages, message) {
	message.text = decodeURIComponent(message.text);
	while (message.text.indexOf("+") != -1)
		message.text = message.text.replace("+", " ");

	var date = new Date(message.timestamp * 1000);
	var format =  wrap(date.getHours(), 2) + ":" + wrap(date.getMinutes(), 2);
	if (message.from != 0) {
		if (message.from == myId) {
			//messages.append('<li><b>user' + message.from + '</b> ' + format  + ': ' + message.text + '</li>' );
                } else {
			messages.append('<li>' + format + ' user' + message.from + ': <font color=\"' + colors[message.from % colors.length] + '\">' + message.text + '</font></li>' );
                }
	} else
		messages.append('<li><font color="black">INF ' + format + ' ' + message.text + '</font></li>' );	
}

function loadMessages(all) {
	return function() {
		$.ajax({
			url: '/messages', 
			method: 'GET',
			dataType: 'json',
			data: {
				all: all
			},
			success: function(data) {
				for (var i = 0; i < data.messages.length; ++i) {
					appendMessage($('#messages'), data.messages[i]);
                                }
				if (data.messages.length != 0) 
					scrollMessages();		
				timer = setTimeout(loadMessages(false), 500);
			}
		});
	}
}

function sendMessage(message) {
	$.ajax({
		url: '/messages', 
		method: 'POST',
		headers: {'Content-Type' : 'text/html; charset=utf-8'},
		data: {
			message: message
		},
		dataType: 'json',
		success: function(response) {
		}
	});
        clearTimeout(timer);
	loadMessages(false)();
}

$(document).ready(function () {
	myId = parseInt(document.cookie.substring(5, document.cookie.indexOf(";")));
        myId = -1;
	$(document).on('keydown', function(event) { 
		if (event.keyCode == 13) {
			event.preventDefault();
			var message = $(this).find('input').val();
			if (message === '')
				return;
			console.log("mes" + message);
			$(this).find('input').val('');
			sendMessage(message);
		}
	});

	loadMessages(true)();
});
