const channelId = 'your_channel_id_here'; // Replace with your actual channel ID
const url = `https://api.thingspeak.com/channels/2992756/feeds.json?results=2`;

async function fetchData() {
    try {
        const response = await fetch(url);
        const data = await response.json();
        const feed = data.feeds[0];
        soli1d1 = Number(feed.field1);
        soli2d1 = Number(feed.field2);

        const display = `
      <p class ="text-xl font-semibold mb-4 text-black-900">Soil Moisture 1: ${soli1d1}</p>
      <p class ="text-xl font-semibold mb-4 text-black-900">Soil Moisture 2: ${soli2d1}</p>
      <p class ="text-xl font-semibold mb-4 text-black-900">Time: ${new Date(feed.created_at).toLocaleString()}</p>
    `;
        document.getElementById('thingspeak').innerHTML = display;
    } catch (error) {
        console.error('Error fetching data:', error);
    }
}

fetchData();
setInterval(fetchData, 5000); // Fetch data every 5 seconds