
window.onload = function(){

    var mobileIcon = document.querySelector('#mobile-icon');
    var mobilePanel = document.querySelector('.mobile-left');

    mobileIcon.onclick = function() {
        if (mobilePanel.style.display === "none") {
            mobilePanel.style.display = "block";
        } else {
            mobilePanel.style.display = "none";
        }
    }

}