import React from "react";
import "./index.css";
fetch = require("node-fetch");
function MovieList() {
  return (
    <div className="layout-column align-items-center mt-50">
      <section className="layout-row align-items-center justify-content-center">
        <input
          type="number"
          className="large"
          placeholder="Enter Year eg 2015"
          data-testid="year-input"
        />
        <button className="" data-testid="submit-button">
          Search
        </button>
      </section>

      <ul className="mt-50 styled" data-testid="movieList">
        <li className="glide-up-fade-in py-10"></li>
      </ul>

      <div className="mt-50 slide-up-fade-in" data-testid="no-result"></div>
    </div>
  );
}

export default MovieList;

function MovieList() {
  const [inputYear, setInputYear] = useState("");
  const [movies, setMovies] = useState([]);
  const [noResults, setNoResults] = useState(false);

  const handleInputChange = (event) => {
    setInputYear(event.target.value);
  };

  const handleSearch = () => {
    if (!inputYear) {
      return; // Don't make an API call if inputYear is empty
    }

    // + Construct the API URL with the inputYear
    const apiUrl = `https://jsonmock.hackerrank.com/api/moviesdata?Year=${inputYear}`;

    fetch(apiUrl)
      .then((response) => response.json())
      .then((data) => {
        if (data.length > 0) {
          setMovies(data.map((movie) => movie.Title));
          setNoResults(false);
        } else {
          setMovies([]);
          setNoResults(true);
        }
      })
      .catch((error) => {
        console.error("Error fetching data:", error);
      });
  };

  return (
    <div className="layout-column align-items-center mt-50">
      <section className="layout-row align-items-center justify-content-center">
        <input
          type="number"
          className="large"
          placeholder="Enter Year eg 2015"
          data-testid="year-input"
          value={inputYear}
          onChange={handleInputChange}
        />
        <button className="" data-testid="submit-button" onClick={handleSearch}>
          Search
        </button>
      </section>

      {noResults ? (
        <div className="mt-50 slide-up-fade-in" data-testid="no-result">
          No Results Found
        </div>
      ) : (
        <ul className="mt-50 styled" data-testid="movieList">
          {movies.map((movie, index) => (
            <li className="glide-up-fade-in py-10" key={index}>
              {movie}
            </li>
          ))}
        </ul>
      )}
    </div>
  );
}
