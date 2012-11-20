/*
    Long Beach Maker Society Build Day
    BUILD Series 101
    
    This program sets up pins 46 through 53 as digital inputs. When those pins see a logic value of "HIGH"
    they will output a tone.
    
    Written By: Ben Cannon October 2012
*/

// #includes put the code thats in the file with same name where the #include would be
 #include "pitches.h"



 // Note durations in music are mathematical; they are are all relative to each other.
 // Their names come from how they are relative to the duration of a WHOLE note.
 // For example: a HALF note is half as long as WHOLE note's duration.  The duration of a 
 // whole note is not a fixed value.  Some music are faster or slower than others.
 // I used 2000 as my WHOLE note duration because I felt it was the right speed for
 // the songs I coded. You can play around with the value to make your song play
 // faster or slower.

 #define W 2000    // Define WHOLE note duration
 #define H W/2     // Define HALF note duration
 #define Q W/4     // Define QUARTER note duration
 #define E W/8     // Define EIGHTH note duration
 #define S W/16    // Define SIXTEENTH note duration

 // DOTTED notes are played 1.5 times the duration of the note.  For example, a DOTTED HALF note
 // is as long as a HALF note PLUS a QUARTER note.
 #define DOT 1.5   // Define dotted note multiplier



// The setup function runs exactly one time and never again. We typically put code here that
// sets up pins, starts serial communications, or things that only need to be done once.
void setup(){
  pinMode (8, INPUT); // Sets pin 8 as an input.
  for(int i = 46; i <= 53; i++)
    pinMode(i, INPUT);            // Set the pin "i" to a digital input.
}



/*
  The Loop block does exactly that. It loops forever!
*/
void loop(){ // From here


  // Sets up potentiometer to be used for pitch bending.
  //
  // Doubling a pitch frequency will get the frequency of the octave of that pitch.
  // To get an additional octave with the potentiometer, I divided the value 
  // that's read by the potentiometer (0-1023) by 1023 to get a range of 0-1.
  // I then increment that by 1 to get a range of 1-2.
  // I can use this range as a multiplier to get all the frequency of the pitch
  // from a pitch to its octave.
  //
  // For example, NOTE_C4*pitchBend will give me all the pitches from C4 to C5
  double pitchBend = ((analogRead(8)/1023.0)+1);



    // First six button are notes of an
    // A minor pentatonic scale: A C D E G A

    // I believe the pentatonic scale is easy and fun to play around with
    // just play or hold any pitch es in any fun rhythm and you will easily
    // create something that just "sounds good."
    if(digitalRead(46))                  // If pin 46 reads a logic high
      tone(37, NOTE_A3*pitchBend);       // Then execute the next line
    else if(digitalRead(47))
      tone(37, NOTE_C4*pitchBend);
    else if(digitalRead(48))
      tone(37, NOTE_D4*pitchBend);
    else if(digitalRead(49))
      tone(37, NOTE_E4*pitchBend);
    else if(digitalRead(50))
      tone(37, NOTE_G4*pitchBend);
    else if(digitalRead(51))
      tone(37, NOTE_A4*pitchBend);



    // The codes for a song are in between { and }
    else if(digitalRead(52))
    {
      // Saria's Song
      // http://img232.imageshack.us/img232/9463/sariassongsinglestaffmn5.jpg
      
      // Measure 1
      tone(37, NOTE_F5); delay(E);  // an eigth note F
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_B5); delay(Q);
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_B5); delay(Q);
      
      // Measure 2
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_B5); delay(E);
      tone(37, NOTE_E6); delay(E);
      tone(37, NOTE_D6); delay(Q);
      tone(37, NOTE_B5); delay(E);
      tone(37, NOTE_C6); delay(E);
      
      // Measure 3
      tone(37, NOTE_B5); delay(E);
      tone(37, NOTE_G5); delay(E);
      tone(37, NOTE_E5); delay(H+E); // Half note tied to eighth note (add)
      tone(37, NOTE_D5); delay(E);
      
      // Measure 4
      tone(37, NOTE_E5); delay(E);
      tone(37, NOTE_G5); delay(E);
      tone(37, NOTE_E5); delay(H*DOT); // Dotted Half note.  Multiply HALF note by DOT multiplier (1.5)
      
      // Measure 5
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_B5); delay(Q);
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_B5); delay(Q);
      
      // Measure 6
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_B5); delay(E);
      tone(37, NOTE_E6); delay(E);
      tone(37, NOTE_D6); delay(Q);
      tone(37, NOTE_B5); delay(E);
      tone(37, NOTE_C6); delay(E);
      
      // Measure 7
      tone(37, NOTE_E6); delay(E);
      tone(37, NOTE_C6); delay(E);
      tone(37, NOTE_G5); delay(H+E); // Half tied with eighth
      tone(37, NOTE_B5); delay(E);
      
      // Measure 8
      tone(37, NOTE_G5); delay(E);
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_E5); delay(Q+S); // Quarter note tied to sixteenth
      tone(37, NOTE_F5); delay(S); 
      tone(37, NOTE_E5); delay(S); 
      tone(37, NOTE_F5); delay(S); 
      tone(37, NOTE_E5); delay(Q); 
      
      // Measure 9
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_E5); delay(E);
      tone(37, NOTE_F5); delay(Q);
      tone(37, NOTE_G5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_B5); delay(Q);
      
      // Measure 10
      tone(37, NOTE_C6); delay(E);
      tone(37, NOTE_B5); delay(E);
      tone(37, NOTE_E5); delay(H*DOT); // Dotted half note
      
      // Measure 11
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_E5); delay(E);
      tone(37, NOTE_F5); delay(Q);
      tone(37, NOTE_G5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_B5); delay(Q);
      
      // Measure 12
      tone(37, NOTE_C6); delay(E);
      tone(37, NOTE_D6); delay(E);
      tone(37, NOTE_E6); delay(H*DOT); // Dotted half note
      
      // Measure 13
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_E5); delay(E);
      tone(37, NOTE_F5); delay(Q);
      tone(37, NOTE_G5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_B5); delay(Q);
      
      // Measure 14
      tone(37, NOTE_C6); delay(E);
      tone(37, NOTE_B5); delay(E);
      tone(37, NOTE_E5); delay(H*DOT); // Dotted half note
      
      // Measure 15
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_C5); delay(E);
      tone(37, NOTE_E5); delay(E);
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_G5); delay(E);
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_G5); delay(E);
      
      // Measure 16
      tone(37, NOTE_B5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_C6); delay(E);
      tone(37, NOTE_B5); delay(E);
      tone(37, NOTE_E6); delay(S);
      tone(37, NOTE_F6); delay(E);
      tone(37, NOTE_D6); delay(S);
      // Measure 17+18
      tone(37, NOTE_E6); delay(W+W); // Two whole notes tied together
    } // End of Saria's Song
    else if(digitalRead(51))
    {
      // Bolero of fire
      // http://www.waveclaw.net:8080/~jdpowell/rings/zelda/songs/zelda%20bolero%20of%20fire%20score.gif
      
      // Measure 1: Piano
      tone(37, NOTE_F4); delay(E);
      tone(37, NOTE_D4); delay(E);
      tone(37, NOTE_F4); delay(E);
      tone(37, NOTE_D4); delay(E);
      tone(37, NOTE_A4); delay(E);
      tone(37, NOTE_F4); delay(E);
      tone(37, NOTE_A4); delay(E);
      tone(37, NOTE_F4); delay(E);
      noTone(37); delay(H);
      
      // Measure 2: Ocarina
      tone(37, NOTE_F5); delay(E); // I made the ocarina an octave higher
      tone(37, NOTE_D5); delay(E); 
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_F5); delay(E);
      noTone(37); delay(H);
      
      // Measure 3: Ocarina
      tone(37, NOTE_G5);  delay(E);
      tone(37, NOTE_E5);  delay(E);
      tone(37, NOTE_G5);  delay(E);
      tone(37, NOTE_E5);  delay(E);
      tone(37, NOTE_AS5); delay(E);
      tone(37, NOTE_G5);  delay(E);
      tone(37, NOTE_AS5); delay(E);
      tone(37, NOTE_G5);  delay(E);
      noTone(37); delay(H);
      
      // Measure 4: Ocarina
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_F5); delay(E);
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_A5); delay(E);
      tone(37, NOTE_F6); delay(E);
      tone(37, NOTE_D5); delay(E);
      tone(37, NOTE_F6); delay(E);
      tone(37, NOTE_D5); delay(E);
      
      // Measure 5: Ocarina
      tone(37, NOTE_A6);  delay(E);
      tone(37, NOTE_E5);  delay(E);
      tone(37, NOTE_A6);  delay(E);
      tone(37, NOTE_E5);  delay(E);
      tone(37, NOTE_G6);  delay(E);
      tone(37, NOTE_CS6); delay(E);
      tone(37, NOTE_G6);  delay(E);
      tone(37, NOTE_CS6); delay(E);
      tone(37, NOTE_F6);  delay(E);
      tone(37, NOTE_A5);  delay(E);
      tone(37, NOTE_F5);  delay(E);
      tone(37, NOTE_E5);  delay(E);
      
      // Measure 6: Ocarina
      tone(37, NOTE_D5); delay(W);
  }  // End of Bolero of fire

    else                      // If no pins are high
        noTone(37);           // then turn off the tone
}// To here
